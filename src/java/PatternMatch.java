/**
 * Problem :
 * Implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * Reference Link :
 * Youtube : https://www.youtube.com/watch?v=l3hda49XcDE
 * Interview Bit : https://www.interviewbit.com/problems/regular-expression-ii/
 * 
 *
 */
public class PatternMatch {

    private static String EMPTY = "";

    public static void main(String[] args) throws Exception {
        System.out.println(isMatch("a*", "aaa"));
        System.out.println(isMatch(".*", "ab"));
        System.out.println(isMatch(".*", "abc"));
        System.out.println(isMatch("....*", "abc"));
        System.out.println(isMatch(".*", ""));
        System.out.println(isMatch(".*.", ""));
        System.out.println(isMatch(".*", "a"));
        System.out.println(isMatch("c*a*b", "aab"));
        System.out.println(isMatch("ab.", "aba"));
        System.out.println(isMatch(".", "ab"));
        System.out.println(isMatch("a*.", "aaa"));
    }

    public static boolean isMatch(String pattern, String str) throws Exception {

        if (EMPTY.equals(pattern) && EMPTY.equals(str) || (".*".equals(pattern) && EMPTY
                .equals(str))) {
            return true;
        }

        if (EMPTY.equals(pattern) || EMPTY.equals(str)) {
            return false;
        }

        String patternPrefix = getPrefixPattern(pattern);

        if (isLooper(patternPrefix)) {                               // cases like “a*” or “.*” etc
            Character loopChar = patternPrefix.charAt(0);
            StringBuffer nextPossibility = new StringBuffer().append(EMPTY);
            String remainingPatternToMatch = pattern.substring(patternPrefix.length());
            do {
                String remainingString = str.substring(nextPossibility.length());
                boolean isFound = isMatch(remainingPatternToMatch, remainingString);
                if (isFound) {
                    return true;
                }
                nextPossibility.append(loopChar);
            } while (isPrefix(str, nextPossibility.toString()));

            return false;
        } else if (isLoneAlphabet(patternPrefix)) {        //cases like ‘a’, ‘b’ etc
            return (pattern.charAt(0) == str.charAt(0)) && isMatch(pattern.substring(1),
                    str.substring(1));
        } else if (isDot(patternPrefix)) {         //case ‘.’
            return isMatch(pattern.substring(1), str.substring(1));
        }

        throw new Exception("Invalid String or pattern");
    }

    private static boolean isPrefix(final String str, final String prefix) {
        if (prefix.startsWith(".")) {
            return prefix.length() <= str.length();
        } else {
            return str.startsWith(prefix);
        }
    }

    private static boolean isLooper(String pattern) {
        return pattern.length() == 2 && pattern.charAt(1) == '*';
    }

    private static boolean isLoneAlphabet(String pattern) {
        return pattern.length() == 1 && pattern.charAt(0) >= 'a' && pattern.charAt(0) <= 'z';
    }

    private static boolean isDot(String pattern) {
        return pattern.length() == 1 && pattern.equals(".");
    }


    private static String getPrefixPattern(String pattern) {
        if (pattern.length() > 0) {
            if (pattern.length() > 1 && pattern.charAt(1) == '*')
                return pattern.substring(0, 2);
            else
                return Character.toString(pattern.charAt(0));
        }

        return EMPTY;

    }

}
