#include <iostream>
#include <string>
using namespace std;

void addNewPatient(string names[5][20], short statuses[5][20])
{
    short specialization;
    string name;
    short status;
    bool badInput = false;

    cout << "Enter specialization , name , status: ";
    cin >> specialization >> name >> status;

    // Handls bad user input
    while (!badInput)
    {
        if ((status != 0 && status != 1) || specialization > 20 || specialization < 1)
        {
            cout << "Invalid Input , try again\nEnter specialization , name , status: ";
            cin >> specialization >> name >> status;
        }
        else
            badInput = true;
    }

    // Checks if the last row of the specified specialization has a name == the specialization is FULL.
    if (names[4][specialization - 1] != "")
        cout << "Sorry we can't add more patients to this specialization\n";
    // IF there's space in the specialization
    else
    {
        // If the status is regular
        if (status == 0)
        {
            // loops to find the available spot
            for (int i = 0; i < 5; i++)
            {
                // Available spot found
                if (names[i][specialization - 1] == "")
                {
                    names[i][specialization - 1] = name;
                    statuses[i][specialization - 1] = status;
                    break;
                }
            }
        }

        // If the status is Urgent
        else if (status == 1)
        {
            // shifts all other patients and puts the urgent patient at the top of the array (first index)
            for (int i = 4; i >= 1; i--)
            {
                names[i][specialization - 1] = names[i - 1][specialization - 1];
                statuses[i][specialization - 1] = statuses[i - 1][specialization - 1];
            }
            // putting the urgent case at the top of the array
            names[0][specialization - 1] = name;
            statuses[0][specialization - 1] = status;
        }
    }
}

void printAllPatients(string names[5][20], short statuses[5][20])
{
    // flag that checks if at least a single patient exists
    bool exist = false;
    for (int i = 0; i < 20; i++)
    {
        // If at least 1 patient is found in specialization
        if (names[0][i] != "")
        {
            exist = true;
            cout << "In specialization: " << i + 1 << " The patients are:\n";
        }
        for (int j = 0; j < 5; j++)
        {
            // while index not empty (not miss any patients in the specialization)
            if (names[j][i] != "")
            {
                cout << names[j][i] << " ";
                if (statuses[j][i] == 1)
                    cout << "Urgent" << endl;
                else
                    cout << "Regular" << endl;
            }
        }
    }

    // If not a single patient exists
    if (!exist)
        cout << "There aren't any patients\n";
}

// doctor picking up a patient
void getNextPatient(string names[5][20], short statuses[5][20])
{
    short specialization;

    cout << "Enter specialization: ";
    cin >> specialization;

    // The patient at the top of the array is called to the doctor
    if (names[0][specialization - 1] != "")
    {
        cout << names[0][specialization - 1] << " go with the doctor please\n";

        // after the patient is called to the doctor , the queue moves and the next patient becomes the top and so on
        // so we shift all the patients whenever a patient is seen by the doctor
        for (int i = 0; i < 4; i++)
        {
            names[i][specialization - 1] = names[i + 1][specialization - 1];
            statuses[i][specialization - 1] = statuses[i + 1][specialization - 1];
        }

        // Handling the last index alone because [i+1] is out of range
        names[4][specialization - 1] = "";
        statuses[4][specialization - 1] = 0;
    }

    // There are no patients in that specialization
    else
        cout << "There are no patients at the moment. Have a rest ,Dr.\n";
}

int main()
{

    // continuity flag
    bool usingg = true;

    // The array holding all the patients' names
    string names[5][20] = {""};
    // The array holding all the statuses of the corresponding patients
    short statuses[5][20] = {0};

    while (usingg)
    {
        int choice{0};

        cout << "Enter your choice:\n1) Add new patient\n2) Print all patients\n3) Get next patient\n4) Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addNewPatient(names, statuses);
            break;
        case 2:
            printAllPatients(names, statuses);
            break;
        case 3:
            getNextPatient(names, statuses);
            break;
        case 4:
            cout << "Thanks for using our system\n";
            // Exiting the loop by making the flag false
            usingg = false;
            break;
        default:
            // handling if the user inputs a choice that doesn't exist
            cout << "Wrong input : Enter a choice correctly you can choose from <1-4> ;)\n";
            continue;
        }
    }

    return 0;
}