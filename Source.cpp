/*
	Credits:

	Name : Muhammad Talha Shafi
	Rollno 23I-0563
	Section : BCS-3D

*/

/*
///////////////////////////////////////////DYNAMIC PLAIGRISM DETECTION TOOL\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
		
		This program is designed to check similarity between two or more documents
		The program performs basic NLP(Natural Language Processing) functions
		It utilizes "Cosine Similarity" to estimate equality in two documents
		No restriction on paragraph size
		Can process multiple documents simulataneously

////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

*/



#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


const int MAX_PATHS = 20 ;
// Global Classes and Variables
// Use of classes is must 

class Input
{
	char ** keyWords;
	int noOfKeyWords;
	int noOfDocs;
	char paths[20][20] = {};

 public:
	 int getNoOfKeyWords()
	 {
		 return noOfKeyWords;
	 }
	 void setNoOfKeyWords(int a)
	 {
		 noOfKeyWords = a;
	 }

	 int getNoOfDocs()
	 {
		 return noOfDocs;
	 }
	 void setNoOfDocs(int a)
	 {
		 noOfDocs = a;
	 }
	
	 char** & getKeywords()
	 {
		 return (char** )keyWords;
	 }
	 char**const & getpaths()
	 {
		 return (char** const)paths;
	 }
};
class Data
{
	
	char** documents;
	double** similarities;
	char** uniqueWords;
	int uniqueCount;
	int** documentFrequency;

public:
	Input input;
	Data();
	double**& getSimilarities();
	char* get(int index);
	void readDoc(int i, char[]);
	void removePunctuation(int i);
	void lower(int a);
	int getSize(char* ptr);//helper func
	void copy(char* dst, char* src, int size);//helper func
	bool cmp(char* pt1, char* pt2);//helper func
	char**& getKeywords();
	void removeKwords(int );
	void getArr(int a, char**& arr, int& size);
	char**& getUniqueWords();
	int getUniqueCount();
	void setUniqueCount(int a);
	int**& docFrequency();
};
double**& Data::  getSimilarities()
{
	return similarities;
}
Data :: Data()
{

	documents = new char* [MAX_PATHS] {};
}
int**& Data :: docFrequency()
{
	return documentFrequency;
}
int Data::getUniqueCount()
{
	return uniqueCount;

}
void Data::setUniqueCount(int a)
{
	uniqueCount = a ;

}
char**& Data:: getUniqueWords()
{
	return uniqueWords;
}
void Data::getArr(int a, char**& arr, int& size)
{
	int s = getSize(documents[a - 1]);
	size = 0;
	for (int i = 0; i < s; i++)
	{
		if (documents[a - 1][i] == ' ')
			size++;
	}
	size++;

	arr = new char* [size] {};
	for (int i = 0 ; i < size  ;i++)
	{
		arr[i] = new char[100] {};
	}

	int index = 0;
	int counter = 0;
	for (int i = 0; i <= s ; i++)
	{
		if (documents[a-1][i] == ' ')
		{
			index = 0;
			counter++;
			continue;
		}
		arr[counter][index++] = documents[a-1][i];
	}


}
void Data::removeKwords(int a)
{
	int size = getSize(documents[a - 1]);
	int index = 0;
	int start = 0;
	char word[100] = {};
	for (int i = 0; i <= size; i++)
	{
		
		if (documents[a - 1][i] == ' ' || documents[a - 1][i] == '.' || documents[a - 1][i] == '\n' || documents[a - 1][i] == '\0' || size  == i )
		{
			for (int j = 0; j < input.getNoOfKeyWords(); j++)
			{

				if (cmp((char*)word, (input.getKeywords()[j])   )  ) 
				{					
					for (int k = start; k < size - (i - start + 1); k++)
					{
						documents[a - 1][k] = documents[a - 1][k + (i - start + 1)];
						
					}
					if (size >= (i - start + 1))
						size -= (i - start + 1);
					else
						size = 0;

					documents[a - 1][size ] = '\0';
					i -= (i - start + 1);
				}

			}


			////////////////////////////////////////
			start = i + 1;
				index = 0;
				for (int i = 0; i < 100; i++)
					word[i] = '\0';

			continue;

		}
		word[index++] = documents[a - 1][i];


	}

}
char**&  Data :: getKeywords()
{
	return (char**)input.getKeywords();
}
void Data :: lower(int a)
{
	int size = getSize(documents[a - 1]);

	for (int i = 0; i < size; i++)
	{
		if (documents[a - 1][i] >= 65 && documents[a - 1][i] < 96)
			documents[a - 1][i] += 32;
	}

}
void Data::removePunctuation(int a)
{
	int size = getSize(documents[a-1]);

	int count = 0; 
	for (int i = size-1; i >= 0 ; i--)
	{
		if ((i!= size-1 && documents[a - 1][i] == ' ' && documents[a - 1][i+1] == ' ')|| (documents[a-1][i] > '0' && documents[a - 1][i] < '9') ||
			documents[a - 1][i] == '.' || 
			documents[a - 1][i] == ',' ||
			documents[a - 1][i] == ';' ||
			documents[a - 1][i] == ':' ||
			documents[a - 1][i] == '!' ||
			documents[a - 1][i] == '?' ||
			documents[a - 1][i] == '-' ||
			documents[a - 1][i] == '\'' ||
			documents[a - 1][i] == '"' ||
			documents[a - 1][i] == '(' ||
			documents[a - 1][i] == ')' ||
			documents[a - 1][i] == '[' ||
			documents[a - 1][i] == ']' ||
			documents[a - 1][i] == '{' ||
			documents[a - 1][i] == '}' ||
			documents[a - 1][i] == '/' ||
			documents[a - 1][i] == '\\' ||
			documents[a - 1][i] == '&' ||
			documents[a - 1][i] == '#' ||
			documents[a - 1][i] == '@' ||
			documents[a - 1][i] == '%' ||
			documents[a - 1][i] == '$' ||
			documents[a - 1][i] == '*' ||
			documents[a - 1][i] == '+' ||
			documents[a - 1][i] == '=' ||
			documents[a - 1][i] == '<' ||
			documents[a - 1][i] == '>' ||
			documents[a - 1][i] == '|' ||
			documents[a - 1][i] == '~' ||
			documents[a - 1][i] == '`' ||
			documents[a - 1][i] == '^')
		{
			count++;
			for (int j = i; j < size-1; j++)
			{
				documents[a - 1][j] = documents[a - 1][j + 1];
			}
			
		}

	}
	
	documents[a - 1][size - count ] = '\0';
	
}
bool Data:: cmp(char* pt1, char* pt2)
{
	for (int i = 0;; i++)
	{
		
		if (pt1[i] != pt2[i])
		{
			return 0;
		}
		if (pt1[i] == '\0')
			break;
	}
	return 1;
}

void Data:: readDoc(int i, char path [] )
{ 
	int ind = 0;
	for (int i = 0;; i++)
	{
		if (path[i] == '\0')
			break;
		if (path[i] == 't' && path[i - 1] == 'x' && path[i - 2] == 't' && path[i - 3] == '.')
			ind = i;

	}
	path[ind + 1] = '\0';

	ifstream file(path, ios::in | ios::binary);

	if (!file) {
		cout << "Unable to open file " << path << std::endl;
		return;
	}


	file.seekg(0, ios::end);
	streampos size = file.tellg();
	file.seekg(0, ios::beg);

	char* res = new char[size] {};
	file.read(res, size);
	res[size] = '\0';

	documents[i - 1] = res;
	file.close();
}
int Data::getSize(char* ptr)
{
	for (int i = 0; ; i++)
	{
		if (ptr[i] == '\0')
			return i;
	}
}

void Data::copy(char* des, char* src , int size)
{
	for (int i = 0; i < size; i++)
	{
		des[i] = src[i];
	}
}



char* Data::get(int index)
{
	if (index <= input.getNoOfDocs())
		return documents[index];
	else
	{
		return (char*)("out of bound");
	}
		
}
Data dataObj;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Function to read input from a file
void readInput(const char* pathofInputFile);

int getNumberOfDocument();

char* getText(int documentNumber);

//// Function to remove punctuation marks from documents
void removePunctuationMarks();
//
//// Function to convert all characters in documents to lowercase
void convertUpperToLowerCase();
//
//// Function to remove stopwords from documents
void removeStopWords();
//
//// Function to generate frequencies of each unique word in each document
void generateFrequencies(char**& uniqueWords, int& uniqueCount, int**& documentFrequency);
//
int getFrequency(char* word, int documentNum);   // -1 if not found
//
void calculateAllCosineSimilarities(double**& similarities, int** documentFrequency);
//
double similarityIn(int doucmentNum1, int documentNum2);



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void readInput(const char* pathofInputFile)
{

	
		std::ifstream file(pathofInputFile, std::ios::in | std::ios::binary);

		if (!file) {
			cout << "Unable to open file " << pathofInputFile << std::endl;
			return ;
		}
		file.seekg(0, ios::end);
		if (file.tellg() == 0) {
			cout  << "The file is empty." << std::endl;
			dataObj.input.setNoOfDocs(0);
			file.close();
			return ;
		}
		// Reset the file pointer to the beginning after checking the size
		file.seekg(0, ios::beg);

		char arr[1000] = {};
		int s_index = 0 , l_index = 0 ;
		file.getline(arr, 1000);
		
		
		if (file.fail()) 
		{
			if (file.eof()) 
			{
				std::cerr << "Error: End of file reached or the file is empty." << std::endl;
			}
			else if (file.bad()) 
			{
				std::cerr << "Error: Bad file stream." << std::endl;
			}
			else 
			{
				std::cerr << "Error: Failed to read the line (buffer might be too small or other issue)." << std::endl;
			}
		}
		

		for (int i = 0; i < 1000 ; i++)
		{
			if (!s_index &&( arr[i]) == ':')
				s_index = i + 2;
			if (arr[i] >= 'A' && arr[i] <= 'z')
			{
				l_index = i;
				
			}


		}
		
		
		int count = 0; 
		for (int i = s_index; i <= l_index; i++)
		{
			if (arr[i] == ' ')
				count++;
		}
		dataObj.input.setNoOfKeyWords(  count + 1);

		
		char**& kwords = dataObj.getKeywords() = new char* [count + 1];//////////////////////////////////////////////////////////

		for (int i = 0; i < count + 1; i++)	
		{
			kwords[i] = new char[100] {};
		}


		int index = 0;
		int counter = 0;
		for (int i = s_index; i <= l_index; i++)
		{
			if (arr[i] == ' ')
			{
				index = 0;
				counter++;
				continue;
			}
			kwords[counter][index++] = arr[i];
		}

		
		

		
		int n;
		file >> n ;
		dataObj.input.setNoOfDocs(n);
		file.ignore(numeric_limits<streamsize>::max(), '\n');  //ignore rest of line
		for (int i = 0; i < n; i++)
		{
			char arr[50] = {""};
			file.getline(arr, 50);
			dataObj.readDoc(i + 1, arr );

		}


		file.close();

	

}
int getNumberOfDocument()
{
	return dataObj.input.getNoOfDocs();
}
char* getText(int documentNumber)
{
	if (documentNumber <= dataObj.input.getNoOfDocs())
		return dataObj.get(documentNumber - 1);
}

void removePunctuationMarks()
{
	for (int i = 0; i < dataObj.input.getNoOfDocs (); i++)
		dataObj.removePunctuation(i + 1);

}

void convertUpperToLowerCase()
{
	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
		dataObj.lower(i + 1);
}

void removeStopWords()
{
	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
		dataObj.removeKwords(i + 1);
}




void generateFrequencies(char**& uniqueWords, int& uniqueCount, int**& documentFrequency)
{
	uniqueCount = 0;
	documentFrequency = new int* [dataObj.input.getNoOfDocs()] {};
	char*** dataArr = new char** [dataObj.input.getNoOfDocs()] {} ;
	int* sizes = new int[dataObj.input.getNoOfDocs()] {};

	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
	{
		
		dataObj.getArr(i + 1, dataArr[i], sizes[i]);
	}
	int sum = 0; 
	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
	{
		sum += sizes[i];
	}
	uniqueWords = new char* [sum] {};
	for (int i = 0; i < sum; i++)
	{
		uniqueWords [i] = new char[100] {};
	}

	int index = 0;

	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
	{
		for (int j = 0; j < sizes[i]; j++)
		{
			bool flag = true;
			for (int k = 0; k < index; k++)
			{
				if (dataObj.cmp(uniqueWords[k], dataArr[i][j]))
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				dataObj.copy(uniqueWords[index++], dataArr[i][j], 9);
				uniqueCount++;
			}

		}
	}
	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
	{
		documentFrequency[i] = new int[uniqueCount] {};
	}
	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
	{
		for (int j = 0; j < sizes[i]; j++)
		{
			for (int k = 0; k < uniqueCount ; k++)
			{
				if (dataObj.cmp(uniqueWords[k], dataArr[i][j]))
				{
					documentFrequency[i][k]++;
				}
			}
		}
	}

	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
	{
		for (int j = 0; j < sizes[i]; j++)
		{
			
			delete[] dataArr[i][j];
			
		}
	}
	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
	{
			delete[] dataArr[i];
	}
	delete[] dataArr;

	dataObj.getUniqueWords() = uniqueWords;
	dataObj.setUniqueCount(uniqueCount) ;
	dataObj.docFrequency() = documentFrequency;


}

int getFrequency(char* word, int documentNum)
{
	for (int i = 0; i < dataObj.getUniqueCount(); i++)
	{
		if (dataObj.cmp(word, dataObj.getUniqueWords()[i]))
		{
			return dataObj.docFrequency()[documentNum-1][i];
		}
	}
	return -1;
}



void calculateAllCosineSimilarities(double**& similarities, int** documentFrequency) {

	similarities = new double* [dataObj.input.getNoOfDocs()] {};
	for (int i = 0; i < dataObj.input.getNoOfDocs(); i++)
	{
		similarities[i] = new double [dataObj.input.getNoOfDocs()] {};
	}
	int number_of_docs = dataObj.input.getNoOfDocs();
	double* magnitudes = new double[number_of_docs];

	for (int i = 0; i < number_of_docs; i++) {
		double sumSquares = 0;
		for (int j = 0; j < dataObj.getUniqueCount(); j++) {
			sumSquares += documentFrequency[i][j] * documentFrequency[i][j];
		}
		magnitudes[i] = sqrt(sumSquares);
	}

	for (int i = 0; i < number_of_docs; i++) 
	{
		for (int j = 0; j < number_of_docs; j++)
		{
			if (i == j) 
			{
				similarities[i][j] = 100; // Cosine similarity with itself is 1
			
			}
			else
			{
				double dotProduct = 0;
				for (int k = 0; k < dataObj.getUniqueCount(); k++)
				{
					dotProduct += documentFrequency[i][k] * documentFrequency[j][k];
				}
				if (magnitudes[i] > 0 && magnitudes[j] > 0) 
				{
					similarities[i][j] =  ( (int) (  10000 * (dotProduct / ((magnitudes[i]) * (magnitudes[j])))  ) )/100.0;
				}
				else 
				{
					similarities[i][j] = 0.0; 
				}
			}
		}
	}
	
	dataObj.getSimilarities() = similarities;
	delete[] magnitudes;
}
double similarityIn(int a, int b)
{

	return (dataObj.getSimilarities()[a-1][b-1]);
}