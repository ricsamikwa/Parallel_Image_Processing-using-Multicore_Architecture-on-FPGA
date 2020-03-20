package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        PrintWriter writer = new PrintWriter("images.h", StandardCharsets.UTF_8);
        writer.print("#define image_0\n" +
                "// #define image_1\n" +
                "// #define image_2\n" +
                "\n");


        processImage(writer, 0);
        processImage(writer, 1);
        processImage(writer, 2);

        writer.close();
    }

    private static void processImage(PrintWriter writer, int number) throws FileNotFoundException {
        writer.print("\n#ifdef image_" + number + "\n" +
                "unsigned char image[] =");
        Scanner scanner = new Scanner(new File("C:\\Users\\ahmad\\Desktop\\IL2202_Project\\ppm conversion\\src\\com\\company\\image" + number + ".ppm"));
        scanner.nextLine();
        scanner.nextLine();
        int horizontal = scanner.nextInt();
        int vertical = scanner.nextInt();
        int max = scanner.nextInt();
        int[] array = new int[horizontal * vertical * 3];

        writer.print("{" + horizontal + "," + vertical + "," + max);
        int i = 0;
        while (scanner.hasNextInt()) {
            array[i] = scanner.nextInt();
            writer.print("," + array[i]);
            i++;
        }
        writer.print("};\n");
        writer.println("#endif");
        writer.println();
        scanner.close();
    }
}
