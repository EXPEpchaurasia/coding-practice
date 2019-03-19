import java.util.Arrays;

public class NthOrderStatistics {

	public static void main(String[] args) throws Exception {
		int[] arr = {7, 9, 5, 1, 3, 8, 4, 2};

		//getMthMin(Arrays.copyOf(arr, arr.length), 0, arr.length-1, 10);

		for (int m = 1; m <= arr.length; ++m){
			System.out.println(getMthMin(Arrays.copyOf(arr, arr.length), 0, arr.length - 1, m));
		}
	}


	public static int getMthMin(int[] arr, int m) {
		int max = arr[0];
		for(int index = 0; index < m; ++index) {
			if(arr[index] > max) max = arr[index];
		}

		int min = arr[m];
		for(int index = m; index < arr.length; ++index) {
			if(arr[index] < min) min = arr[index];
		}

		return Math.min(max, min);
	}

	public static int getMthMin(int arr[], int start, int end, int m) throws Exception {
		System.out.println("Attempting " + m + "th smallest number from : " + Arrays.toString(Arrays.copyOfRange(arr, start,end+1)));
		//Edge cases
		if(start > end || m < 1 || m > (end - start + 1)) {
			throw new Exception("Meaningful message here");
		}

		if(end - start == 0) {
			return arr[start];
		}

		int low = start+1;
		int high = end;
		int pivot = start;

		while(true) {
			while(low < end && arr[low] < arr[pivot]) {
				++low;
			}

			while(high > start && arr[high] > arr[pivot]) {
				--high;
			}

			if(low < high) {
				swap(arr, low, high);
			} else {
				break;
			}
		}
		swap(arr, high, pivot);

		int sortedPos = high - start + 1;
		if(m == sortedPos) {
			return arr[high];
		} else if (m < sortedPos) {
			return getMthMin(arr, start, high - 1, m);
		} else {
			return getMthMin(arr, high + 1, end, m - sortedPos);
		}

	}

	private static void swap(int []arr, int index1, int index2 ) {
		int temp = arr[index1];
		arr[index1]  = arr[index2];
		arr[index2] = temp;
	}

}
