// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// $Id: //acds/rel/13.0sp1/ip/merlin/altera_merlin_router/altera_merlin_router.sv.terp#1 $
// $Revision: #1 $
// $Date: 2013/03/07 $
// $Author: swbranch $

// -------------------------------------------------------
// Merlin Router
//
// Asserts the appropriate one-hot encoded channel based on 
// either (a) the address or (b) the dest id. The DECODER_TYPE
// parameter controls this behaviour. 0 means address decoder,
// 1 means dest id decoder.
//
// In the case of (a), it also sets the destination id.
// -------------------------------------------------------

`timescale 1 ns / 1 ns

module nios_system_addr_router_001_default_decode
  #(
     parameter DEFAULT_CHANNEL = 2,
               DEFAULT_WR_CHANNEL = -1,
               DEFAULT_RD_CHANNEL = -1,
               DEFAULT_DESTID = 19 
   )
  (output [95 - 91 : 0] default_destination_id,
   output [26-1 : 0] default_wr_channel,
   output [26-1 : 0] default_rd_channel,
   output [26-1 : 0] default_src_channel
  );

  assign default_destination_id = 
    DEFAULT_DESTID[95 - 91 : 0];

  generate begin : default_decode
    if (DEFAULT_CHANNEL == -1) begin
      assign default_src_channel = '0;
    end
    else begin
      assign default_src_channel = 26'b1 << DEFAULT_CHANNEL;
    end
  end
  endgenerate

  generate begin : default_decode_rw
    if (DEFAULT_RD_CHANNEL == -1) begin
      assign default_wr_channel = '0;
      assign default_rd_channel = '0;
    end
    else begin
      assign default_wr_channel = 26'b1 << DEFAULT_WR_CHANNEL;
      assign default_rd_channel = 26'b1 << DEFAULT_RD_CHANNEL;
    end
  end
  endgenerate

endmodule


module nios_system_addr_router_001
(
    // -------------------
    // Clock & Reset
    // -------------------
    input clk,
    input reset,

    // -------------------
    // Command Sink (Input)
    // -------------------
    input                       sink_valid,
    input  [106-1 : 0]    sink_data,
    input                       sink_startofpacket,
    input                       sink_endofpacket,
    output                      sink_ready,

    // -------------------
    // Command Source (Output)
    // -------------------
    output                          src_valid,
    output reg [106-1    : 0] src_data,
    output reg [26-1 : 0] src_channel,
    output                          src_startofpacket,
    output                          src_endofpacket,
    input                           src_ready
);

    // -------------------------------------------------------
    // Local parameters and variables
    // -------------------------------------------------------
    localparam PKT_ADDR_H = 64;
    localparam PKT_ADDR_L = 36;
    localparam PKT_DEST_ID_H = 95;
    localparam PKT_DEST_ID_L = 91;
    localparam PKT_PROTECTION_H = 99;
    localparam PKT_PROTECTION_L = 97;
    localparam ST_DATA_W = 106;
    localparam ST_CHANNEL_W = 26;
    localparam DECODER_TYPE = 0;

    localparam PKT_TRANS_WRITE = 67;
    localparam PKT_TRANS_READ  = 68;

    localparam PKT_ADDR_W = PKT_ADDR_H-PKT_ADDR_L + 1;
    localparam PKT_DEST_ID_W = PKT_DEST_ID_H-PKT_DEST_ID_L + 1;



    // -------------------------------------------------------
    // Figure out the number of bits to mask off for each slave span
    // during address decoding
    // -------------------------------------------------------
    localparam PAD0 = log2ceil(64'h400000 - 64'h200000); 
    localparam PAD1 = log2ceil(64'h401000 - 64'h400800); 
    localparam PAD2 = log2ceil(64'h401080 - 64'h401000); 
    localparam PAD3 = log2ceil(64'h4010a0 - 64'h401080); 
    localparam PAD4 = log2ceil(64'h4010c0 - 64'h4010a0); 
    localparam PAD5 = log2ceil(64'h4010d0 - 64'h4010c0); 
    localparam PAD6 = log2ceil(64'h4010e0 - 64'h4010d0); 
    localparam PAD7 = log2ceil(64'h4010f0 - 64'h4010e0); 
    localparam PAD8 = log2ceil(64'h401100 - 64'h4010f0); 
    localparam PAD9 = log2ceil(64'h401110 - 64'h401100); 
    localparam PAD10 = log2ceil(64'h401120 - 64'h401110); 
    localparam PAD11 = log2ceil(64'h401128 - 64'h401120); 
    localparam PAD12 = log2ceil(64'h401130 - 64'h401128); 
    localparam PAD13 = log2ceil(64'h10000000 - 64'h8000000); 
    // -------------------------------------------------------
    // Work out which address bits are significant based on the
    // address range of the slaves. If the required width is too
    // large or too small, we use the address field width instead.
    // -------------------------------------------------------
    localparam ADDR_RANGE = 64'h10000000;
    localparam RANGE_ADDR_WIDTH = log2ceil(ADDR_RANGE);
    localparam OPTIMIZED_ADDR_H = (RANGE_ADDR_WIDTH > PKT_ADDR_W) ||
                                  (RANGE_ADDR_WIDTH == 0) ?
                                        PKT_ADDR_H :
                                        PKT_ADDR_L + RANGE_ADDR_WIDTH - 1;

    localparam RG = RANGE_ADDR_WIDTH-1;

      wire [PKT_ADDR_W-1 : 0] address = sink_data[OPTIMIZED_ADDR_H : PKT_ADDR_L];

    // -------------------------------------------------------
    // Pass almost everything through, untouched
    // -------------------------------------------------------
    assign sink_ready        = src_ready;
    assign src_valid         = sink_valid;
    assign src_startofpacket = sink_startofpacket;
    assign src_endofpacket   = sink_endofpacket;

    wire [PKT_DEST_ID_W-1:0] default_destid;
    wire [26-1 : 0] default_src_channel;





    nios_system_addr_router_001_default_decode the_default_decode(
      .default_destination_id (default_destid),
      .default_wr_channel   (),
      .default_rd_channel   (),
      .default_src_channel  (default_src_channel)
    );

    always @* begin
        src_data    = sink_data;
        src_channel = default_src_channel;
        src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = default_destid;

        // --------------------------------------------------
        // Address Decoder
        // Sets the channel and destination ID based on the address
        // --------------------------------------------------

    // ( 0x200000 .. 0x400000 )
    if ( {address[RG:PAD0],{PAD0{1'b0}}} == 28'h200000   ) begin
            src_channel = 26'b00000000000010;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 20;
    end

    // ( 0x400800 .. 0x401000 )
    if ( {address[RG:PAD1],{PAD1{1'b0}}} == 28'h400800   ) begin
            src_channel = 26'b00000000000001;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 0;
    end

    // ( 0x401000 .. 0x401080 )
    if ( {address[RG:PAD2],{PAD2{1'b0}}} == 28'h401000   ) begin
            src_channel = 26'b00000010000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 18;
    end

    // ( 0x401080 .. 0x4010a0 )
    if ( {address[RG:PAD3],{PAD3{1'b0}}} == 28'h401080   ) begin
            src_channel = 26'b00000001000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 22;
    end

    // ( 0x4010a0 .. 0x4010c0 )
    if ( {address[RG:PAD4],{PAD4{1'b0}}} == 28'h4010a0   ) begin
            src_channel = 26'b00000000100000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 21;
    end

    // ( 0x4010c0 .. 0x4010d0 )
    if ( {address[RG:PAD5],{PAD5{1'b0}}} == 28'h4010c0   ) begin
            src_channel = 26'b10000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 6;
    end

    // ( 0x4010d0 .. 0x4010e0 )
    if ( {address[RG:PAD6],{PAD6{1'b0}}} == 28'h4010d0   ) begin
            src_channel = 26'b01000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 5;
    end

    // ( 0x4010e0 .. 0x4010f0 )
    if ( {address[RG:PAD7],{PAD7{1'b0}}} == 28'h4010e0   ) begin
            src_channel = 26'b00100000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 4;
    end

    // ( 0x4010f0 .. 0x401100 )
    if ( {address[RG:PAD8],{PAD8{1'b0}}} == 28'h4010f0   ) begin
            src_channel = 26'b00010000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 8;
    end

    // ( 0x401100 .. 0x401110 )
    if ( {address[RG:PAD9],{PAD9{1'b0}}} == 28'h401100   ) begin
            src_channel = 26'b00001000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 7;
    end

    // ( 0x401110 .. 0x401120 )
    if ( {address[RG:PAD10],{PAD10{1'b0}}} == 28'h401110   ) begin
            src_channel = 26'b00000100000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 9;
    end

    // ( 0x401120 .. 0x401128 )
    if ( {address[RG:PAD11],{PAD11{1'b0}}} == 28'h401120   ) begin
            src_channel = 26'b00000000010000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 10;
    end

    // ( 0x401128 .. 0x401130 )
    if ( {address[RG:PAD12],{PAD12{1'b0}}} == 28'h401128   ) begin
            src_channel = 26'b00000000001000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 11;
    end

    // ( 0x8000000 .. 0x10000000 )
    if ( {address[RG:PAD13],{PAD13{1'b0}}} == 28'h8000000   ) begin
            src_channel = 26'b00000000000100;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 19;
    end

end


    // --------------------------------------------------
    // Ceil(log2()) function
    // --------------------------------------------------
    function integer log2ceil;
        input reg[65:0] val;
        reg [65:0] i;

        begin
            i = 1;
            log2ceil = 0;

            while (i < val) begin
                log2ceil = log2ceil + 1;
                i = i << 1;
            end
        end
    endfunction

endmodule


