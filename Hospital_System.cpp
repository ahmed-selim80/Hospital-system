#include <iostream>
#include <string>
using namespace std;

void addNewPatient(string names[5][20], int statuses[5][20])
{
    short specialization;
    string name;
    int status;

    cout << "Enter specialization , name , status: ";
    cin >> specialization >> name >> status;

    if ((status != 0 && status != 1) || specialization > 20 || specialization < 1)
    {
        cout << "Invalid Input , try again\nEnter specialization , name , status: ";
        cin >> specialization >> name >> status;
    }

    if (names[4][specialization - 1] != "")
        cout << "Sorry we can't add more patients to this specialization\n";
    else
    {
        if (status == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                if (names[i][specialization - 1] == "")
                {
                    names[i][specialization - 1] = name;
                    statuses[i][specialization - 1] = status;
                    break;
                }
            }
        }

        else if (status == 1)
        {
            for (int i = 4; i >= 1; i--)
            {
                names[i][specialization - 1] = names[i - 1][specialization - 1];
                statuses[i][specialization - 1] = statuses[i - 1][specialization - 1];
            }
            names[0][specialization - 1] = name;
            statuses[0][specialization - 1] = status;
        }

        for (int i = 0; i < 5; i++)
        {

            cout << names[i][specialization - 1] << " ";
            if (statuses[i][specialization - 1] == 1)
                cout << "Urgent" << endl;
            else
                cout << "Regular" << endl;
        }
        cout << endl;
    }
}

void printAllPatients(string names[5][20], int statuses[5][20])
{
    for (int i = 0; i < 20; i++)
    {
        if (names[0][i] != "")
            cout << "In specialization: " << i + 1 << " The patients are:\n";
        for (int j = 0; j < 5; j++)
        {
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
}

void getNextPatient(string names[5][20], int statuses[5][20])
{
    short specialization;

    cout << "Enter specialization: ";
    cin >> specialization;

    if (names[0][specialization - 1] != "")
    {
        cout << names[0][specialization - 1] << " go with the doctor please\n";

        for (int i = 0; i < 4; i++)
        {
            names[i][specialization - 1] = names[i + 1][specialization - 1];
            statuses[i][specialization - 1] = statuses[i + 1][specialization - 1];
        }

        names[4][specialization - 1] = "";
        statuses[4][specialization - 1] = 0;
    }

    else
        cout << "There are no patients at the moment. Have a rest ,Dr.\n";
}

int main()
{
    bool usingg = true;

    string names[5][20] = {""};
    int statuses[5][20] = {0};

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
            usingg = false;
            break;
        default:
            cout << "Wrong input : Enter a choice correctly you can choose from <1-4> ;)\n";
            continue;
        }
    }

    return 0;
}