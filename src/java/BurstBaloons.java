/**
 * We have been given N balloons, each with a number of coins associated with it.
 * On bursting a balloon i, the number of coins gained is equal to A[i-1]*A[i]*A[i+1].
 * Also, balloons i-1 and i+1 now become adjacent.
 * Find the maximum possible profit earned after bursting all the balloons. Assume an extra 1 at each boundary.
 */
public class BurstBaloons {
	public static void main(String[] args) {
		System.out.println(maxBenefit(new int []{1, 2, 3, 4, 5}));
		System.out.println(maxBenefit(new int []{3, 1, 5, 8}));
	}

	private static int maxBenefit(final int[] array) {
		int []baloons = new int[array.length + 2];
		baloons[0] = baloons[baloons.length-1] = 1;
		int maxBenefit[][] = new int[baloons.length][baloons.length];

		for (int index = 1; index < baloons.length-1; ++index) {
			baloons[index] = array[index-1];
		}

		for (int length = 1; length < baloons.length-1; ++ length) {
			for(int start = 1; start <= baloons.length - length - 1; ++start) {
				int end = start + length - 1;
				for(int burstPoint = start; burstPoint <= end; ++burstPoint) {
					maxBenefit[start][end] = Math.max(maxBenefit[start][end],
														maxBenefit[start][burstPoint - 1]
														+ maxBenefit[burstPoint + 1][end]
														+ baloons[start-1] * baloons[burstPoint] * baloons[end+1]);
				}

			}
		}

		return maxBenefit[1][baloons.length-2];
	}

}
