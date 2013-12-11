//Make a diamond part 2
//By Casey Megginson

import java.util.Scanner;
//import java.lang.Math;

public class diamond2{
  public static void main(String [] args){
    int size, reference, reference2, maxSpaces;
    Scanner sc = new Scanner(System.in);

    System.out.print("Diamond size (must be odd): ");
    size = sc.nextInt();

    while(size % 2 == 0){ //Make sure that the input is odd and bitch if it isn't
      System.out.print("Enter an ODD number: ");
      size = sc.nextInt();
    }

    //Prep variables for the loops based on input

    maxSpaces = size / 2;
    reference = maxSpaces;
    reference2 = 1;
    
    for(int lines = 0; lines < size; lines++){ //For loop based on the individual lines
      for(int spaces = 0; spaces <= Math.abs(reference); spaces++){ //For loop for printing spaces
        System.out.print(" ");
      }
      for(int stars = 1; stars <= reference2; stars++){ //For loop for printing stars
        System.out.print("*");
      }
      System.out.println(""); //Prepping the loop for the next pass
      reference--;
      
      if(lines < maxSpaces){ //Makes sure to increment stars on the first half and decrement on the second half
        reference2 += 2;
      }
      else{
        reference2 -= 2;
      }
    }
  }
}
