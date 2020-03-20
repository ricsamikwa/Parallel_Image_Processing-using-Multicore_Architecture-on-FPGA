module custom_cpu(CLOCK_50,SW,KEYS,REDLED,GREENLED,HEX_HIGH,HEX_LOW,KEY_RS);
	input CLOCK_50;
	input[17:0] SW;
	input[3:0] KEYS;
	input[0:0] KEY_RS;
	output[17:0] REDLED;
	output[7:0] GREENLED;
	output[27:0] HEX_HIGH;
	output[27:0] HEX_LOW;
	
	nios_system NiosII(
		.clk_clk(CLOCK_50),         //      clk.clk
		.reset_reset_n(KEY_RS),   //    reset.reset_n
		.sw_export(SW),       //       sw.export
		.keys_export(KEYS),     //     keys.export
		.redled_export(REDLED),   //   redled.export
		.greenled_export(GREENLED), // greenled.export
		.hex_high_export(HEX_HIGH), // hex_high.export
		.hex_low_export(HEX_LED)   //  hex_low.export
	);
endmodule