/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * Example :
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 * If it is not possible to reach the end index, return -1.
 *
 * Reference Links :
 * InterviewBit : https://www.interviewbit.com/problems/min-jumps-array/
 * GeeksForGeeks : https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
 * Youtube Tutorial : https://www.youtube.com/watch?v=cETfFsSTGJI
 */
class MinArrayJump {

    public static void main(String[] args) {
        int[] array = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
        //      index: 0  1  2  3  4  5  6  7  8  9  10
        System.out.println(minJump(array, 0));
        System.out.println(minJump(array));
        System.out.println(minJumpOrderN(array));
        System.out.println(minJumpOrderN(new int[] {1, 2, 1, 7, 7, 2, 3, 1, 1, 1}));
    }

    /**
     * Recursive solution with exponential n pow(n - 1) time complexity.
     */
    public static int minJump(int[] array, int currentIndex) {

        int maxAllowedJump = array.length - (currentIndex + 1);
        int min = maxAllowedJump;
        for (int jump = 1; (jump <= array[currentIndex]) && (jump <= maxAllowedJump); ++jump) {

            int thisJump = 1 + minJump(array, currentIndex + jump);
            if (thisJump < min) {
                min = thisJump;
            }
        }
        //System.out.println("Minimum jumps from index " + currentIndex + " is : " + min);
        return min;
    }

    /**
     * Iterative solution with exponential n pow (2) time complexity. and
     * n extra auxilary space complexity.
     */
    public static int minJump(int[] numbers) {
        int minJumpsFrom[] = new int[numbers.length];
        minJumpsFrom[numbers.length - 1] = 0;
        System.out.println(
                "Minimum jumps from index " + (numbers.length - 1) + " element (" + numbers[
                        numbers.length - 1] + ") is : " + minJumpsFrom[numbers.length - 1]);

        for (int index = numbers.length - 2; index >= 0; --index) {
            int maxAllowedJumps = numbers.length - index - 1;
            int minJumps = maxAllowedJumps;
            for (int jumps = 1; jumps <= numbers[index] && jumps <= maxAllowedJumps; jumps++) {
                int thisJump = 1 + minJumpsFrom[index + jumps];
                minJumps = Math.min(thisJump, minJumps);
            }
            minJumpsFrom[index] = minJumps;
            System.out.println(
                    "Minimum jumps from index " + index + "  element (" + numbers[index] + ") is : "
                            + minJumpsFrom[index]);
        }

        return minJumpsFrom[0];
    }

    /**
     * Iterative solution with Order (n) time complexity and
     * O(1) extra auxilary space.
     */
    public static int minJumpOrderN(int[] numbers) {
        if (numbers == null) {
            return -1;
        }

        if (numbers.length == 1) {
            return 0;
        }

        printArray(numbers);

        int jumpsSoFar = 1;
        int maxReachableIndex = 1;
        int stepsRemaining = numbers[0];

        for (int index = 1; index < numbers.length; ++index) {

            if (index == numbers.length - 1) {
                break;
            }

            maxReachableIndex = Math.max(maxReachableIndex, index + numbers[index]);

            if (maxReachableIndex >= numbers.length - 1) {
                jumpsSoFar++;
                break;
            }

            stepsRemaining--;

            if (stepsRemaining == 0) {
                jumpsSoFar++;

                stepsRemaining = maxReachableIndex - index;
            }
        }
        return jumpsSoFar;
    }

    public static void printArray(int[] arr) {

        System.out.println("*********************************");
        for (int index = 0; index < arr.length; ++index) {
            System.out.print(arr[index] + "\t");
        }
        System.out.println();

    }



}
