#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() 
	{
		saveData = new Baby[totalBirths];
	}

	// destructor
	~MedicalRecord() 
	{
		delete[] saveData;

		cout << "Object is being deleted" << endl;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) 
	{
		ifstream myfile(filename);

		if (myfile.is_open()) 
		{
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) 
			{
				cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() 
	{
		int Count = 0;
		int previous = 0;
		string totalofName;

		for (int i = 0; i < NumofB; i++)
		{
			for (int j = 0; j < NumofB; j++)
			{
				if (saveData[i].getName() == saveData[j].getName())
				{
					Count++;
				}
			}
			if (Count > previous)
			{
				totalofName = saveData[i].getName();
				previous = Count;
				Count = 0;
			}
		}
		return totalofName;
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() 
	{	
		return NumofB;
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() 
	{
		int lowBweight = 0;

		for (int i = 0; i < NumofB; i++)
		{
			if (saveData[i].getWeight() < 2500)
			{
				lowBweight++;
			}
		}
		return lowBweight;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) 
	{
		int numofSamename = 0;

		for (int i = 0; i < NumofB; i++)
		{
			if (saveData[i].getName() == s)
			{
				numofSamename++;
			}
		}
		return numofSamename;
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) 
	{
		saveData[NumofB] = b;
		NumofB++;	//break error here
	}

	Baby* saveData;
	int NumofB = 0;
	int totalBirths = 1000;
};
