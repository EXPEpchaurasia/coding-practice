/**
 * Problem Statement :
 * Given two words A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * Insert a character
 * Delete a character
 * Replace a character
 * Example :
 * edit distance between
 * "Anshuman" and "Antihuman" is 2.
 *
 * Operation 1: Replace s with t.
 * Operation 2: Insert i.
 *
 *
 * Reference Links :
 * Youtube : https://www.youtube.com/watch?v=We3YDTzNXEk
 * Interview Bit : https://www.interviewbit.com/problems/edit-distance/
 */
public class OneDiffApart {

    public static void main(String[] args) {
        System.out.println(hasMaxEditDistance("honda", "hyundai", 2));

    }

    public static boolean areSimilar(String s1, String s2) {

        int length1 = s1.length();
        int length2 = s2.length();

        if (length1 == length2) {
            int diffs = 0;
            for (int index = 0; index < length1 && diffs < 2; ++index) {
                if (s1.charAt(index) != s2.charAt(index)) {
                    ++diffs;
                }
            }
            return diffs < 2;
        } else if (Math.abs(length1 - length2) > 1) {
            return false;
        } else {
            if (length1 > length2) {
                return hasOneDiff(s1, s2);
            } else {
                return hasOneDiff(s2, s1);
            }
        }

    }

    public static boolean hasOneDiff(String s1, String s2) {
        int index1 = 0, index2 = 0;
        for (; index1 < s1.length() && index2 < s2.length(); ++index1, ++index2) {
            if (s1.charAt(index1) != s2.charAt(index2)) {
                return s1.substring(index1 + 1).equals(s2.substring(index2));
            }
        }
        return true;
    }

    public static Boolean hasMaxEditDistance(String s1, String s2, int maxED) {
        if (Math.abs(s1.length() - s2.length()) > maxED) {
            return false;
        }

        int[][] editDistance = new int[s1.length() + 1][s2.length() + 1];
        initialize(editDistance);

        for (int index = 0; index <= s2.length(); ++index) {
            editDistance[0][index] = index;
        }

        for (int index = 0; index <= s1.length(); ++index) {
            editDistance[index][0] = index;
        }

        editDistance[s1.length()][s2.length()] = maxED + 1;
        int DELETE_COST = 1, INSERT_COST = 1, REPLACE_COST = 2;

        for (int coloumn = 1; coloumn <= s2.length(); ++coloumn) {
            for (int row = 1; row <= s1.length(); ++row) {
                editDistance[row][coloumn] = min(editDistance[row - 1][coloumn] + INSERT_COST,
                        editDistance[row][coloumn - 1] + DELETE_COST,
                        editDistance[row - 1][coloumn - 1] + (REPLACE_COST) * (
                                s1.charAt(row - 1) == s2.charAt(coloumn - 1) ? 0 : 1));

            }
            printArray(editDistance);
        }

        printArray(editDistance);
        return editDistance[s1.length()][s2.length()] <= maxED;
    }

    public static int min(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }

    public static void printArray(int[][] arr) {
        int maxColoumn = arr[0].length;
        int maxRow = arr.length;
        System.out.println("*********************************");
        for (int row = 0; row < maxRow; ++row) {
            for (int coloumn = 0; coloumn < maxColoumn; ++coloumn) {
                System.out.print(arr[row][coloumn] + "\t");
            }
            System.out.println();
        }

    }

    public static void initialize(int[][] arr) {
        int maxColoumn = arr[0].length;
        int maxRow = arr.length;
        for (int row = 0; row < maxRow; ++row) {
            for (int coloumn = 0; coloumn < maxColoumn; ++coloumn) {
                arr[row][coloumn] = -1;
            }
        }

    }
}
