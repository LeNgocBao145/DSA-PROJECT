#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

void sort(int* arr, 
		  int n, 
		  int choice, 
	      int &comparision,
		  double &time);

int convertAlgorithmToChoice(string str);
string convertChoiceToAlgorithm(int choice);
bool isAllDigits(string str);

bool readFile(string file_name, int &size, int* &arr);
bool generateData(string file_name, int size, int order);

int main(int argc, char** argv) {
	if (argc < 5) {
		cout << "Too few arguments" << endl;
	}
	else if (argc > 6) {
		cout << "Too many arguments" << endl;
	}
	else {
		bool valid_algorithm = true;
		int comparision = 0;
		double time = 0;
		string mode = argv[1];
		if (mode == "-a") {
			cout << "ALGORITHM MODE" << endl;
			// algorithm
			cout << "Algorithm: ";
			string algorithm = argv[2];
			int choice = convertAlgorithmToChoice(algorithm);
			string algorithm_str = convertChoiceToAlgorithm(choice);
			if (algorithm_str != "") {
				cout << algorithm_str << endl;
			}
			else valid_algorithm = false;
			

			// command 1
			if (argc == 5 && valid_algorithm && !isAllDigits(argv[3])) {
				bool valid_file = false;
				string file_name = argv[3];
				int input_size = 0;
				int* arr = NULL;

				cout << "Input file: " << file_name << endl;
				valid_file = readFile(file_name, input_size, arr);

				cout << "Input size: " << input_size << endl;
				/* Sorting here */
				if (valid_file) {
					sort(arr, input_size, choice, comparision, time);
				}
				else {
					cout << "Input file missing or corrupted" << endl;
					return 1;
				}
				delete[] arr;
				arr = NULL;
				/**/

				// output params
				string output = argv[3];
				cout << "-----------------------------------" << endl;
				if (valid_file && output == "-comp") {
					cout << "Comparisions: " << comparision << endl;
				}
				else if (valid_file && output == "-time") {
					cout << "Running time: " << time << endl;
				}
				else if (valid_file && output == "-both") {
					cout << "Running time: " << time << endl;
					cout << "Comparisions: " << comparision << endl;
				}
				else {
					cout << "Invalid output parameter" << endl;
				}
			}
			// command 2
			else if (argc == 6 && valid_algorithm) {
			   	// input size
				bool valid_size = true;
				string input_size_str = argv[3];
				int input_size = 0;
				int* arr = NULL;


				// check digits
				valid_size = isAllDigits(input_size_str);
				//

				input_size = stoi(input_size_str);

				if (input_size <= 0 || input_size > 1000000) {
					valid_size = false;
				}
				
				if (valid_size) {
					cout << "Input size: " << input_size << endl;
 				}
				else {
					cout << "Invalid input size" << endl;
				}
				
				//
				// input order
				bool valid_order = true;
				int order = 0;
				string input_order = argv[4];
				if (input_order == "-rand" && valid_size) {
					cout << "Input order: Randomized" << endl;
					order = 1;
				}
				else if (input_order == "-nsorted" && valid_size) {
					cout << "Input order: Nearly sorted" << endl;
					order = 2;
				}
				else if (input_order == "-sorted" && valid_size) {
					cout << "Input order: Sorted" << endl;
					order = 3;
				}
				else if (input_order == "-rev" && valid_size) {
					cout << "Input order: Reversed" << endl;
					order = 4;
				}
				else {
					cout << "Invalid input order" << endl;
					valid_order = false;
				}
				//		

				bool valid_file = true;
				generateData("input.txt", input_size, order);
				valid_file = readFile("input.txt", input_size, arr);
				
				/* Sorting here */
				if (valid_file) {
					sort(arr, input_size, choice, comparision, time);
				}
				delete[] arr;
				arr = NULL;
				/**/

				// output params
				string output = argv[5];
				cout << "-----------------------------------" << endl;
				if (valid_order && output == "-comp") {
					cout << "Comparisions: " << comparision << endl;
				}
				else if (valid_order && output == "-time") {
					cout << "Running time: " << time << endl;
				}
				else if (valid_order && output == "-both") {
					cout << "Running time: " << time << endl;
					cout << "Comparisions: " << comparision << endl;
				}
				else {
					cout << "Invalid output parameter" << endl;
				}
			}
			// command 3
			else if (argc == 5 && valid_algorithm && isAllDigits(argv[3])) {
				bool valid_size = true;
				string input_size_str = argv[3];
				int input_size = stoi(input_size_str);

				if (input_size <= 0 || input_size > 1000000) {
					valid_size = false;
					cout << "Size out of range (1 - 1000000)" << endl;
					return 1;
				}

				cout << "Input size: " << input_size << endl;

				int order = 1;
				int* arr = NULL;
				bool valid_file = false;

				cout << endl;
				
				for (order = 1; order <= 4; order++) {
					switch (order)
					{
					case 1: 
						cout << "Input order: Randomized" << endl;
						break;
					case 2:
						cout << "Input order: Nearly sorted" << endl;
						break;
					case 3:
						cout << "Input order: Sorted" << endl;
						break;
					case 4:
						cout << "Input order: Reversed" << endl;
						break;
					default:
						break;
					}
					cout << "--------------------------------" << endl;

					generateData("input.txt", input_size, order);
					valid_file = readFile("input.txt", input_size, arr);

					/* Sorting here */
					if (valid_file) {
						sort(arr, input_size, choice, comparision, time);
					}
		
					delete[] arr;
					arr = NULL;
					/**/

					// output params
					string output = argv[4];
					cout << "-----------------------------------" << endl;
					if (output == "-comp") {
						cout << "Comparisions: " << comparision << endl;
					}
					else if (output == "-time") {
						cout << "Running time: " << time << endl;
					}
					else if (output == "-both") {
						cout << "Running time: " << time << endl;
						cout << "Comparisions: " << comparision << endl;
					}
					else {
						cout << "Invalid output parameter" << endl;
					}

					cout << endl;
				}

			}
			

		}

		else if (mode == "-c") {
			cout << "COMPARE MODE" << endl;
			string algorithm_1 = argv[2];
			int algorithm_1_choice = convertAlgorithmToChoice(algorithm_1);

			string algorithm_2 = argv[3];
			int algorithm_2_choice = convertAlgorithmToChoice(algorithm_2);

			string algorthm_1_str = convertChoiceToAlgorithm(algorithm_1_choice);
			string algorthm_2_str = convertChoiceToAlgorithm(algorithm_2_choice);

			cout << "Algorithm: " << algorthm_1_str << " | " << algorthm_2_str << endl;
			
			int comp1 = 0, comp2 = 0;
			double time1 = 0, time2 = 0;

			if (algorithm_1_choice != -1
				&& algorithm_2_choice != -1) {
				// command 4
				if (argc == 5) {
					int* arr = NULL;
					int input_size = 0;
					string file_name = argv[4];

					cout << "Input file: " << file_name << endl;
					bool valid_file = readFile(file_name, input_size, arr);

					cout << "Input size: " << input_size << endl;
					
					
					if (valid_file) {
						sort(arr, input_size, algorithm_1_choice, comp1, time1);
						delete[] arr;
						arr = NULL;
						readFile(file_name, input_size, arr);
						
						sort(arr, input_size, algorithm_2_choice, comp2, time2);
						delete[] arr;
						arr = NULL;
					}
					else {
						cout << "Input file missing or corrupted" << endl;
						return 1;
					}
					cout << "-------------------------------------" << endl;
					cout << "Running time: " << time1 << " | " << time2 << endl;
					cout << "Comparisions: " << comp1 << " | " << comp2 << endl;
					
				}
				// command 5
				else if (argc == 6) {
					bool valid_size = true;
					string input_size_str = argv[4];
					int input_size = 0;
					if (isAllDigits(input_size_str)) {
						input_size = stoi(input_size_str);
					}
					else valid_size = false;

					if (input_size <= 0 || input_size > 1000000) {
						valid_size = false;
						cout << "Size out of range (1 - 1000000)" << endl;
						return 1;
					}

					cout << "Input size: " << input_size << endl;

					// input order
					bool valid_order = true;
					int order = 0;
					string input_order = argv[4];
					if (input_order == "-rand" && valid_size) {
						cout << "Input order: Randomized" << endl;
						order = 1;
					}
					else if (input_order == "-nsorted" && valid_size) {
						cout << "Input order: Nearly sorted" << endl;
						order = 2;
					}
					else if (input_order == "-sorted" && valid_size) {
						cout << "Input order: Sorted" << endl;
						order = 3;
					}
					else if (input_order == "-rev" && valid_size) {
						cout << "Input order: Reversed" << endl;
						order = 4;
					}
					else {
						cout << "Invalid input order" << endl;
						valid_order = false;
					}
					//		
					int* arr = NULL;

					bool valid_file = true;
					generateData("input.txt", input_size, order);
					valid_file = readFile("input.txt", input_size, arr);

					if (valid_file) {
						sort(arr, input_size, algorithm_1_choice, comp1, time1);
						delete[] arr;
						arr = NULL;

						readFile("input.txt", input_size, arr);
						sort(arr, input_size, algorithm_2_choice, comp2, time2);
						delete[] arr;
						arr = NULL;
					}

					cout << "-------------------------------------" << endl;
					cout << "Running time: " << time1 << " | " << time2 << endl;
					cout << "Comparisions: " << comp1 << " | " << comp2 << endl;
					
				}
			}
			else {
				cout << "Invalid algorithm arguments" << endl;
			}
		}
	}

	return 0;
}

bool readFile(string file_name, int &size, int* &arr) {
	// Bao Pham
	return false;
}
bool generateData(string file_name, int size, int order) {
	/* order:
		1: randomized
		2: nearly sorted
		3: sorted
		4: reversed
	*/

	// Bao Pham
	return false;
}

int convertAlgorithmToChoice(string str) {
	if (str == "selection") {
		return 1;
	}
	else if (str == "insertion") {
		return 2;
	}
	else if (str == "bubble") {
		return 3;
	}
	else if (str == "heap") {
		return 4;
	}
	else if (str == "merge") {
		return 5;
	}
	else if (str == "quick") {
		return 6;
	}
	else if (str == "radix") {
		return 7;
	}
	else if (str == "shaker") {
		return 8;
	}
	else if (str == "shell") {
		return 9;
	}
	else if (str == "counting") {
		return 10;
	}
	else if (str == "flash") {
		return 11;
	}
	else {
		return -1;
	}
}

string convertChoiceToAlgorithm(int choice) {
	if (choice == 1) return "Selection sort";
	if (choice == 2) return "Insertion sort";
	if (choice == 3) return "Bubble sort";
	if (choice == 4) return "Heap sort";
	if (choice == 5) return "Merge sort";
	if (choice == 6) return "Quick sort";
	if (choice == 7) return "Radix sort";
	if (choice == 8) return "Shaker sort";
	if (choice == 9) return "Shell sort";
	if (choice == 10) return "Counting sort";
	if (choice == 11) return "Flash sort";
	return "";
}

bool isAllDigits(string str) {
	for (unsigned int i = 0; i < str.size(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

void sort(int* arr, int n, int choice, int& comparision,
	double& time) {
	/* choice:
		1: selection sort
		2: insertion sort
		3: bubble sort
		4: heap sort
		5: merge sort
		6: quick sort
		7: radix sort
		8: shaker sort
		9: shell sort
		10: counting sort
		11: flash sort
	*/ 



	switch (choice) {
	case 1: 
		
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:

		break;
	case 7:

		break;
	case 8:

		break;
	case 9:

		break;
	case 10:

		break;
	case 11:

		break;
	default:
		break;
	}

}