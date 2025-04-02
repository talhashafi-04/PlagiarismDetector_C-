# Plagiarism Checker in C++

## Overview

This tool helps detect plagiarism by comparing the similarity between multiple text documents using Cosine Similarity. It preprocesses text by cleaning it, removing stop words, and then computes a similarity score based on word frequencies.

## Features

- Reads and processes text files from `input.txt`
- Removes punctuation and stop words
- Converts uppercase letters to lowercase
- Generates word frequency vectors
- Computes Cosine Similarity to determine document similarity
- Outputs similarity scores with two decimal precision

## Usage

### Input File (`input.txt`)

The first line contains stop words (space-separated, in lowercase). The second line contains the number of documents. The following lines list the document filenames.

Example:

```
Stop Words: the of also was a an is to it too
2
document1.txt
document2.txt
```

### Running the Tool

#### Compilation (Linux/Mac)

```bash
g++ -o plagiarism_checker plagiarism_checker.cpp
./plagiarism_checker
```

#### Compilation (Windows - Visual Studio)

1. Open Visual Studio.
2. Create a new C++ console application.
3. Add `plagiarism_checker.cpp` to the project.
4. Build and run.

### Example Documents

#### `document1.txt`

```
John likes to, watch movies. Mary: likes movies too.
```

#### `document2.txt`

```
Mary also’ likes # to& watch football games.
```

### Output Example

```
Document 1 vs Document 2 Similarity: 53.94%
```

## Functionality Breakdown

1. **Reads Input**: Parses `input.txt` to extract stop words and document paths.
2. **Preprocessing**: Cleans text by removing punctuation, extra spaces, and stop words.
3. **Word Frequency Analysis**: Identifies unique words and calculates word frequencies.
4. **Cosine Similarity Calculation**: Computes the similarity score between documents.

## Function List

- `void readInput(const char* pathofInputFile)` - Reads input file.
- `int getNumberOfDocument()` - Returns document count.
- `char* getText(int documentNumber)` - Retrieves document text.
- `void removePunctuationMarks()` - Cleans text of punctuation.
- `void convertUpperToLowerCase()` - Converts text to lowercase.
- `void removeStopWords()` - Removes stop words from text.
- `void generateFrequencies(char**& uniqueWords, int& uniqueCount, int**& documentFrequency)` - Extracts unique words and counts them.
- `int getFrequency(char* word, int documentNum)` - Returns word frequency in a document.
- `void calculateAllCosineSimilarities(double**& similarities, int** documentFrequency)` - Computes similarity scores.
- `double similarityIn(int documentNum1, int documentNum2)` - Returns the similarity score of two documents.

## System Requirements

- C++17 or later
- A compatible compiler (g++ or MSVC)

## Contribution

Contributions are welcome! Feel free to fork the repository and submit pull requests.

## License

This project is released under the MIT License.

## Author

Talha Shafi

