import java.util.Collections;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

public class WordLex {

	public static void main(String[] args) throws Exception {
		List<String> words = new ArrayList<String>();
		WordLex wordLex = new WordLex();
		char[] word = new char[]{'a','a','a'};
		for (int i = 0; i < 17574; ++i) {
			//System.out.println("Inserted Word is " + new String(word));
			words.add(new String(word));
			wordLex.buildNextWord(word);
		}

		System.out.println("Results is : " + wordLex.getFirstOutOfSeqWord(words, 3));
	}

	public String getFirstOutOfSeqWord(List<String> wordList, int length) throws Exception {

		if(wordList == null || wordList.isEmpty()) {
			throw new Exception("List is null/empty");
		}

		if(length < 1) {
			throw new Exception("Length is invalid");
		}

		char[] wordToCheck = new char[length];
		for(int i = 0; i < length;) {
			wordToCheck[i++] = 'a';
		}

		Set<String> uniqueWords = new HashSet<String>(wordList);

		while(true) {
			String thisWord = new String(wordToCheck);
			//System.out.println("Generated Word is " + thisWord);
			if( !uniqueWords.contains(thisWord)) {
				return thisWord;
			}
			try {
				buildNextWord(wordToCheck);
			} catch (Exception e) {
				System.out.println(e.getMessage());
				return "";
			}

		}
	} 


	private void buildNextWord(char[] wordToCheck) throws Exception {
		for(int index = wordToCheck.length-1 ; index >=0 ; --index) {
			if(wordToCheck[index] != 'z') {
				wordToCheck[index]++;
				return;
			} else {
				wordToCheck[index] = 'a';
			}
		}
		throw new Exception("Reached End of Sequence");

	}
}
