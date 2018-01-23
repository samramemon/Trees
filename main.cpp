/*
 * Binary Search Tree implementation - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations
 * Now also doing testing & height calculations
 *
 *
 *
 */

#include <iostream>
#include <queue>
#include <fstream>
#include <cstring>
#include "BST.h"
#include "TestData.h"
#include <math.h>
using namespace std;

/*
 *  Interface to run all tests if --test is passed on command line
 */

void runTests() {
	cout << " [x] Running tests. " << endl;
	TestData *testing = new TestData();			// Create object with testing data and interfaces

  BST<int> *bst_test = new BST<int>;

	/* Should make a tree like this:
              10
         5          14
     1      7           17
                            19
                          18

   */
	int testval = testing->get_next_minitest();
	while( testval >= 0 ){
		bst_test->add( testval, bst_test->getRoot());
		testval = testing->get_next_minitest();
	}
	cout << " [x] Should print out in pre order: 10 5 1 7 14 17 19 18 " << endl;
  cout << " [x] Resulting print out test:      ";
	bst_test->printPreOrder(bst_test->getRoot());
  cout << endl;

	cout << " [x] Should print a tree height of  : 5" << endl;
  cout << " [x] Currently calculating height of: ";
  cout << bst_test->height(bst_test->getRoot());
  cout << endl;
}


/*
 * Generate the CSV file for the project output here
 */
void genCSV() {
	ofstream MyFile;
	MyFile.open("Output.csv", ios::out | ios::ate | ios::app | ios::binary);
	Node <int>  *pCurr = nullptr, *pPrev = NULL;
	int count = 0;
	int i = 0;

	cout << " [x] Generating CSV output file. " << endl;
	cout << " [!!!] UNIMPLEMENTED - Need to generate the CSV file based on the tree height growth." << endl;
	BST <int> *bst_sorted = new BST <int>;
	BST <int> *bst_balanced = new BST <int>;
	BST <int> *bst_scrambled1 = new BST <int>;
	BST <int> *bst_scrambled2 = new BST <int>; 
	BST <int> *bst_scrambled3 = new BST <int>;
	BST <int> *bst_scrambled4 = new BST <int>;
	BST <int> *bst_scrambled5= new BST <int>;
	
	TestData *test = new TestData();
	// TestData *test_balanced = new TestData();
	// TestData *test_scrambled1 = new TestData();
	// TestData *test_scrambled2 = new TestData();
	// TestData *test_scrambled3 = new TestData();
	// TestData *test_scrambled4 = new TestData();
	// TestData *test_scrambled5 = new TestData();
	
	int sorted = test->get_next_sorted();
	int balanced = test->get_next_balanced();
	int scrambled1 = test->get_next_scrambled(1);
	int scrambled2 = test->get_next_scrambled(2);
	int scrambled3 = test->get_next_scrambled(3);
	int scrambled4 = test->get_next_scrambled(4);
	int scrambled5 = test->get_next_scrambled(5);

MyFile<<"N,log_2(N), sorted,balanced,srambled1, srambled2, srambled3, srambled4, srambled5"<<endl;
	while(sorted >= 0 || balanced>=0 || scrambled1>=0 || scrambled2 >= 0 || scrambled3 >= 0 || scrambled4 >= 0 || scrambled5 >= 0){
		
		bst_sorted->add(sorted, bst_sorted->getRoot());
		bst_balanced->add(balanced, bst_balanced->getRoot());
		bst_scrambled1->add(scrambled1, bst_scrambled1->getRoot());
		bst_scrambled2->add(scrambled2, bst_scrambled2->getRoot());
		bst_scrambled3->add(scrambled3, bst_scrambled3->getRoot());
		bst_scrambled4->add(scrambled4, bst_scrambled4->getRoot());
		bst_scrambled5->add(scrambled5, bst_scrambled5->getRoot());
		MyFile << bst_sorted->nodesCount(bst_sorted->getRoot()) <<
			"," << log2(bst_sorted->nodesCount(bst_sorted->getRoot())) <<
			"," <<bst_sorted->height(bst_sorted->getRoot()) <<
			"," <<bst_balanced->height(bst_balanced->getRoot()) <<
			"," <<bst_scrambled1->height(bst_scrambled1->getRoot()) <<
			"," <<bst_scrambled2->height(bst_scrambled2->getRoot()) <<
			"," <<bst_scrambled3->height(bst_scrambled3->getRoot()) <<
			"," <<bst_scrambled4->height(bst_scrambled4->getRoot()) <<
			"," <<bst_scrambled5->height(bst_scrambled5->getRoot()) << endl;
		
		scrambled5 = test->get_next_scrambled(5);
		scrambled4 = test->get_next_scrambled(4);
		scrambled3 = test->get_next_scrambled(3);
		scrambled2 = test->get_next_scrambled(2);
		scrambled1 = test->get_next_scrambled(1);
		balanced = test->get_next_balanced();
		sorted = test->get_next_sorted();
		
	}
	
	cout << "Sorted height: " << bst_sorted->height(bst_sorted->getRoot()) << endl;
	cout<<"Balanced height: "<< bst_balanced->height(bst_balanced->getRoot()) << endl;
	cout << "Scrambled#1 height: " << bst_scrambled1->height(bst_scrambled1->getRoot()) << endl;
	cout << "Scrambled#2 height: " << bst_scrambled2->height(bst_scrambled2->getRoot()) << endl;
	cout << "Scrambled#3 height: " << bst_scrambled3->height(bst_scrambled3->getRoot()) << endl;
	cout << "Scrambled#4 height: " << bst_scrambled4->height(bst_scrambled4->getRoot()) << endl;
	cout << "Scrambled#5 height: " << bst_scrambled5->height(bst_scrambled5->getRoot()) << endl;

    // make a file: OutputData-BST.csv
		// make 7 trees (sorted, balanced, scrambled[0..4])

	// fill trees with data from TestData
		//  -- as you fill, get the heights and output to CSV file: log_2 N, height sorted, height balanced, height scrambled[0..4]
    //  -- fill until the get_next_* functions return -1
}


/*
 *   Main function for execution
 */
int main( int argc, char* argv[] ) {
	if( argc > 1 && !strcmp(argv[1], "--test") )
	{
		cout << " [x] Program in test mode, doing simple tests. " << endl;
		runTests();  // testing should just do a simple tree insert set and search
	}
	else
	{
		cout << " [x] Program built and running in full CSV generation mode. " << endl;
		runTests();
		genCSV();
	}
	return 0;
}
