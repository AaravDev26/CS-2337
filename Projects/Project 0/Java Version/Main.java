// Aarav Dev 
// axd220001

import java.lang.Math;
import java.io.*;
import java.util.*;
import java.util.Scanner;
import java.io.IOException;

public class Main
{
   static String[] names = new String[31];
   static String[] records = new String[31];
   static int numPlayers = 0;
   static double[] battingAverages = new double[31];
   static double[] onBasePercentages = new double[31];
   static int[] numHits = new int[31];
   static int[] numWalks = new int[31];
   static int[] numStrikeouts = new int[31];
   static int[] numHitsByPitch = new int[31];
   
   
   
   public static void main(String[] args) throws IOException
   {
      // Create a Scanner object for input
      Scanner s = new Scanner(System.in);

      // Get name of file
      System.out.print("Enter the filename: ");
      String fileName = s.nextLine();

      // Open file
      File f = new File(fileName);
      s = new Scanner(f);
      
      // Read lines from the file until none remaining
      while (s.hasNext())
      {
         // Read the next name.
         String name = s.nextLine();
         
         String[] tokens = name.split(" ");
         for (int i = 0; i < 31; i++)
         {
            if (names[i] == null)
            {
               names[i] = tokens[0];
               break;
            }
         }
         for (int i = 0; i < 31; i++)
         {
            if (records[i] == null)
            {
               records[i] = tokens[1];
               break;
            }
         }
      }

      // Close the file.
      s.close();
      
      for (String n: names)
         if (n != null)
            numPlayers++;
      
      int index = 0;
      while (names[index] != null && index < 31)
      {
         String temp = records[index];
         double hits = 0.0;
         double outs = 0.0;
         double strikeouts = 0.0;
         double walks = 0.0;
         double hitByPitch = 0.0;
         double sacrifices = 0.0;
         for (int i = 0; i < temp.length(); i++)
         {
            if (temp.charAt(i) == 'H')
            {
               hits += 1.0;
            }
            if (temp.charAt(i) == 'O')
            {
               outs += 1.0;
            }
            if (temp.charAt(i) == 'K')
            {
               strikeouts += 1.0;
            }
            if (temp.charAt(i) == 'W')
            {
               walks += 1.0;
            }
            if (temp.charAt(i) == 'P')
            {
               hitByPitch += 1.0;
            }
            if (temp.charAt(i) == 'S')
            {
               sacrifices += 1.0;
            }
         }
         double battingAverage = 0.0;
         double onBasePercentage = 0.0;
         double atBats = hits + outs + strikeouts;
         double plateAps = hits + outs + strikeouts + walks + hitByPitch + sacrifices;
         if (atBats == 0.0)
            battingAverage = 0.0;
         else
            battingAverage = getBattingAverage(hits, atBats);
         if (plateAps == 0.0)
            onBasePercentage = 0.0;
         else
            onBasePercentage = getOnBasePercentage(hits, walks, hitByPitch, plateAps);
         battingAverages[index] = battingAverage;
         onBasePercentages[index] = onBasePercentage;
         numHits[index] = (int) hits;
         numWalks[index] = (int) walks;
         numStrikeouts[index] = (int) strikeouts;
         numHitsByPitch[index] = (int) hitByPitch;
         System.out.println(names[index]);
         System.out.println("BA: " + String.format("%.3f", battingAverage));
         System.out.println("OB%: " + String.format("%.3f", onBasePercentage));
         System.out.println("H: " + (int) hits);
         System.out.println("BB: " + (int) walks);
         System.out.println("K: " + (int) strikeouts);
         System.out.println("HBP: " + (int) hitByPitch);
         if (index < numPlayers)
            System.out.println("");
         index++;
      }
      
      int[] numStrikes = new int[numPlayers];
      for (int i = 0; i < numStrikes.length; i++)
         numStrikes[i] = numStrikeouts[i];
      
      System.out.println("LEAGUE LEADERS");
      System.out.println("BA: " + leadersD(names, battingAverages).toString().replace("[", "").replace("]", "") + " " + String.format("%.3f", getMaxD(battingAverages)));
      System.out.println("OB%: " + leadersD(names, onBasePercentages).toString().replace("[", "").replace("]", "") + " " + String.format("%.3f", getMaxD(onBasePercentages)));
      System.out.println("H: " + leaders(names, numHits).toString().replace("[", "").replace("]", "") + " " + getMax(numHits));
      System.out.println("BB: " + leaders(names, numWalks).toString().replace("[", "").replace("]", "") + " " + getMax(numWalks));
      System.out.println("K: " + leadersMin(names, numStrikes).toString().replace("[", "").replace("]", "") + " " + getMin(numStrikes));
      System.out.println("HBP: " + leaders(names, numHitsByPitch).toString().replace("[", "").replace("]", "") + " " + getMax(numHitsByPitch));
   }
   
   public static double getBattingAverage(double hits, double atBats)
   {
      return hits/atBats;
   }
   
   public static double getOnBasePercentage(double hits, double walks, double hitByPitch, double plateAps)
   {
      return (hits + walks + hitByPitch)/plateAps;
   }
   
   public static int getMax(int[] arr)
   {
      int max = arr[0];
      for (int i = 0; i < arr.length; i++)
      {
         if (arr[i] > max)
            max = arr[i];
      }
      return max;
   }
   
   public static double getMaxD(double[] arr)
   {
      double max = arr[0];
      for (int i = 0; i < arr.length; i++)
      {
         if (arr[i] > max)
            max = arr[i];
      }
      return max;
   }
   
   public static int getIndex(int[] arr)
   {
      int max = 0;
      for (int i = 0; i < arr.length; i++)
      {
         if (arr[i] > arr[max])
            max = i;
      }
      return max;
   }
   
   public static int getIndexD(double[] arr)
   {
      int max = 0;
      for (int i = 0; i < arr.length; i++)
      {
         if (arr[i] > arr[max])
            max = i;
      }
      return max;
   }
   
   public static int getMin(int[] arr)
   {
      int smallest = arr[0];

      for(int i =1;i<arr.length;i++)  
      {
          if(arr[i]<smallest)
          {
           smallest=arr[i];
          }
      }
      return smallest;
   }
   
   public static List<String> leadersD(String[] names, double[] totals) 
   {
    List<String> winners = new ArrayList<>();
    int n = names.length;
    double max = 0.0;
    for (int i = 0; i < n; ++i) {
        double raised = totals[i];
        if (raised >= max) {
            if (raised > max) {
                winners.clear();
                max = raised;
            }
            if (names[i] != null)
               winners.add(names[i]);
        }
    }
    
      return winners;
   }
   
   public static List<String> leaders(String[] names, int[] totals) {
    List<String> winners = new ArrayList<>();
    int n = names.length;
    double max = 0.0;
    for (int i = 0; i < n; ++i) {
        double raised = totals[i];
        if (raised >= max) {
            if (raised > max) {
                winners.clear();
                max = raised;
            }
            if (names[i] != null)
               winners.add(names[i]);
        }
    }
      return winners;
   }
   
   public static List<String> leadersMin(String[] names, int[] totals) {
      List<String> winners = new ArrayList<>();
      int min = getMin(totals);
      for (int i = 0; i < totals.length; ++i) {
      if (totals[i] == min && names[i] != null)
      {
         winners.add(names[i]);
      }
      
        
    }
    return winners;
   }
}
