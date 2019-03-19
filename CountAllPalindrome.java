import java.util.HashSet;
import java.util.Set;

public class CountAllPalindrome {
	public static void main(String[] args) {
		//System.out.println(getMaxPalindromeCount("abba"));
		System.out.println(getMaxPalindromeCount("acbcagcggcg"));

	}

	public static int getMaxPalindromeCount(String str) {
		Set<String> palindromes = new HashSet<String>();

		if(str == null || str.isEmpty()) {
			return 0;
		}

		int length = str.length();
		if(length == 1) {
			return 1;
		}

		boolean[][] isPalindrome = new boolean[length][length];
		int[][] maxPalindrome = new int[length][length];

		for(int index = 0; index < length; ++index) {
			isPalindrome[index][index] = true;
			maxPalindrome[index][index] = 0;
		}

		for(int start = 0; start < length-1; ++start) {
			int end = start + 1;
			isPalindrome[start][end] = (str.charAt(start) == str.charAt(end));
			maxPalindrome[start][end] = (isPalindrome[start][end] ? 1 : 0);
			if(isPalindrome[start][end]) {
				palindromes.add(str.substring(start, end+1));
			}
		}

		for(int palLen = 3; palLen <= length; ++palLen) {
			for(int start = 0; start <= length - palLen; ++start) {
				int end = start + palLen - 1;
				isPalindrome[start][end] = isPalindrome[start+1][end-1] && (str.charAt(start) == str.charAt(end));
				maxPalindrome[start][end] = maxPalindrome[start][end-1]
											+ maxPalindrome[start+1][end]
											- maxPalindrome[start+1][end-1]
											+ (isPalindrome[start][end] ? 1 : 0);

				if(isPalindrome[start][end]) {
					palindromes.add(str.substring(start, end+1));
				}
			}
		}

		System.out.println("isPalindrome array is : "); printArray(isPalindrome);
		System.out.println("maxPalCount array is : "); printArray(maxPalindrome);
		printPalindroms(palindromes);
		return maxPalindrome[0][length-1];
	}

	private static void printPalindroms(final Set<String> palindromes) {
		System.out.println("Palindromes are : ");
		for(String palindrome : palindromes) {
			System.out.println(palindrome);
		}
		System.out.println("*********************************");
	}

	public static void printArray(int[][] arr) {
		int maxColoumn = arr[0].length;
		int maxRow = arr.length;
		System.out.println("*********************************");
		for(int row = 0; row < maxRow; ++row) {
			for(int coloumn = 0; coloumn < maxColoumn; ++coloumn) {
				System.out.print(arr[row][coloumn] + "\t");
			}
			System.out.println();
		}

	}

	public static void printArray(boolean[][] arr) {
		int maxColoumn = arr[0].length;
		int maxRow = arr.length;
		System.out.println("*********************************");
		for(int row = 0; row < maxRow; ++row) {
			for(int coloumn = 0; coloumn < maxColoumn; ++coloumn) {
				System.out.print(arr[row][coloumn] ? "T" : "F");
				System.out.print("\t");
			}
			System.out.println();
		}

	}


}
