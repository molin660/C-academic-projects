#include <stdio.h>
#include <stdlib.h> // for malloc(), free()
#include <string.h>

#include "word_extractor.h"
#include "word_tally.h"

/**
 * A tool to hold the words we care about in an array, and
 * provide a method for processing the file.
 *
 */

// forward declarations
static int updateWordInTallyList(LLNode **wordLists, int maxLen, char *word);

/*
 * Here we do all the work, processing the
 * file and determining what to do for each word as we
 * read it.  Once we are done reading, we can then
 * examine our wordsToCheck list and see what their
 * state is
 */
int tallyWordsInFile(char *filename, LLNode **wordLists, int maxLen) {
	struct WordExtractor *wordExtractor = NULL;
	wordExtractor = weCreateExtractor(filename, maxLen); // create the extractor and open the file
	if (wordExtractor == NULL) {
		fprintf(stderr, "Failed creating extractor for '%s'\n", filename);
		return 0;
	}

	char *aWord = NULL;
	// add any more variables that you need
	int totalWordCount = 0;

	/** TODO: ensure that all of the word list heads are NULL */

	for (int i = 0; i < maxLen; i++) {
		wordLists[i] = NULL;
	}

	// read each word from the file using the WordExtractor,
	// and for each tally how often it has been used in
	// the appropriate list

	// In the loop, figure out whether we have seen this
	// word before, and do the appropriate thing if we have

	while (weHasMoreWords(wordExtractor)) { //counting total # of words in LL
		aWord = weGetNextWord(wordExtractor);
		totalWordCount++;

		int wordLen = strlen(aWord);

		if (wordLen < 0 || wordLen >= maxLen) {
			fprintf(stderr, "word length out of range: \n");
		}

		// figure out whether we have seen this word before,
		// and do the appropriate thing if we have
		updateWordInTallyList(wordLists, maxLen, aWord);

	}

	// is there anything else you need to do at the end of the loop?
	printf("Total word count %d\n", totalWordCount);

	// Close the file when we are done
	weDeleteExtractor(wordExtractor);
	return 1;
}

/**
 * TODO: Either update the tally in the list, or add it to the list
 */
static int updateWordInTallyList(LLNode **wordListHeads, int maxLen, char *word) {

	/* TODO: look up the word in the correct list to see
	 * if we have already seen it */

	LLNode * tempNode = llLookupKey(wordListHeads[strlen(word)], word);

	/* TODO: if the word is in the list, then update the tally
	 * in the node and we are done so return success */
	if (tempNode != NULL) {
		//printf("before: %d", tempNode->value)
		tempNode->value++;
	}

	/** TODO: otherwise add it to the list */
	else {
		LLNode * newNode = NULL; //adding words to the LL
		newNode = llNewNode(word, 1);
		newNode->key = malloc(sizeof(char) * (strlen(word) + 1));
		strcpy(newNode->key, word);
		wordListHeads[strlen(word)] = llAppend(wordListHeads[strlen(word)], newNode);
	}

	/** return success if no error */
	return 1;
}