/************************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Implementation file for the Zoo class. The Zoo class
**               is used to keep track of the zoo's progress. With each
**               day in one year, animals are fed, a random event occurs,
**               profits are calculated, and the player can buy a new
**               animal. If there is no money left, ends the game. If
**               money is left, player can choose to continue to a new
**               day or end the day.
************************************************************************/

#include "Zoo.hpp"


/***********************************************************************
** Description: Default constructor for the Zoo class. Sets the max
**              number of each animal type for an exhibit to 10, the
**              initial number of animals in each exhibit to 0, and
**              dynamically creates arrays for each of the four
**              animals species at the zoo.
***********************************************************************/
Zoo::Zoo()
{
    maxTurtles = 10;
    maxPenguins = 10;
    maxTigers = 10;
    maxNewAnimals = 10;

    numTurtles = 0;
    numPenguins = 0;
    numTigers = 0;
    numNewAnimals = 0;

    turtleList = new Turtle[maxTurtles];
    penguinList = new Penguin[maxPenguins];
    tigerList = new Tiger[maxTigers];
    newAnimalList = new NewAnimal[maxNewAnimals];
}


/***********************************************************************
** Description: Void member function playGame keeps track of each day
**              at the zoo. Calls function settingUpZoo to set up the
**              initial zoo. Keeps track of the number of baby/adult
**              animals in the zoo each day. Feeds animals, plays a 
**              random event, and gives players the option to buy a new
**              animal. Calculates profits earned. If no money is left
**              or the year is over, ends the game.
***********************************************************************/
void Zoo::playGame()
{
    int choice,
        dayNum,
        goToNextDay;
    const int DAYS_IN_YEAR = 365;

    //Keeps track of the day number
    dayNum = 0;

    //Pick initial animals for the zoo and then end the day
    settingUpZoo();
    goToNextDay = 1;

    //Game ends after one year passes, if the user quits, or if no money left
    while (dayNum < DAYS_IN_YEAR && goToNextDay == 1
                  && (bankAccount.getBalance() > 0))
    {
        int totalAnimals,
            foodQuality,
            babyTurtles = 0,
            adultTurtles = 0,
            babyPenguins = 0,
            adultPenguins = 0,
            babyTigers = 0,
            adultTigers = 0,
            babyNewAnim = 0,
            adultNewAnim = 0;

        double bonus,
               turtleProfit,
               penguinProfit,
               tigerProfit,
               newAnimalProfit,
               totalProfit;

        dayNum++;
        cout << endl << "Day " << dayNum << endl << endl;

        cout << "Current balance: $" << bankAccount.getBalance() << endl;

        cout << endl << "Current animals:" << endl;

        //Aging up turtles, finding number of adults/babies
        ageAnimals(turtleList, numTurtles, adultTurtles, babyTurtles);
        cout << "Adult turtles: " << adultTurtles << endl;
        cout << "Baby turtles: " << babyTurtles << endl;

        //Aging up penguins, finding number of adults/babies
        ageAnimals(penguinList, numPenguins, adultPenguins, babyPenguins);
        cout << "Adult penguins: " << adultPenguins << endl;
        cout << "Baby penguins: " << babyPenguins << endl;

        //Aging up tigers, finding number of adults/babies
        ageAnimals(tigerList, numTigers, adultTigers, babyTigers);
        cout << "Adult tigers: " << adultTigers << endl;
        cout << "Baby tigers: " << babyTigers << endl;

        //Aging up new animal, finding number of adults/babies
        for (int i = 0; i < numNewAnimals; i++)
        {
            ++newAnimalList[i];
            if (newAnimalList[i].isAdult())
            {
                adultNewAnim++;
            }

            else
            {
                babyNewAnim++;
            }
            
        }
        cout << "Adult " << newAnimalName << ": " << adultNewAnim << endl;
        cout << "Baby " << newAnimalName << ": " << babyNewAnim 
             << endl << endl;

        //Determining if there are any animals to feed/play random event
        totalAnimals = numTurtles + numPenguins + numTigers + numNewAnimals;
        if (totalAnimals == 0)
        {
            cout << "You do not have any animals left in the zoo." << endl;
        }

        //Plays when there is at least one animal in the zoo
        else
        {
            //Feeding animals
            foodQuality = chooseFoodQuality();

            //Returns any bonus made from random event
            bonus = randomEvent(foodQuality);

            //Calculating profit made by each animal
            cout << endl << "Profits for today: " << endl;
            cout << fixed << showpoint << setprecision(2);

            turtleProfit = animalProfits(turtleList, numTurtles);
            cout << "The turtle exhibit made $" << turtleProfit << endl;

            penguinProfit = animalProfits(penguinList, numPenguins);
            cout << "The penguin exhibit made $" << penguinProfit << endl;

            tigerProfit = animalProfits(tigerList, numTigers);
            cout << "The tiger exhibit made $" << tigerProfit << endl;

            newAnimalProfit = animalProfits(newAnimalList, numNewAnimals);
            cout << "The " << newAnimalName << " exhibit made $" 
                 << newAnimalProfit << endl;

            //If any bonus from random event
            if (bonus != 0)
            {
                cout << "Bonus earned: $" << bonus << endl;
            }

            //Finding total money made in a day
            totalProfit = turtleProfit + penguinProfit + tigerProfit + 
                          newAnimalProfit + bonus;
            cout << "Total profit: $" << totalProfit << endl << endl;

            //Adding profit to bank account
            bankAccount.depositMoney(totalProfit);
        }

        //Option to buy animal if still have money
        if (bankAccount.getBalance() > 0)
        {
            buyAnimal();
        }

        //Lose the game if out of money
        if (bankAccount.getBalance() <= 0)
        {
            cout << "You do not have any money left. "
                 << "The game is over." << endl << endl;
        }

        else
        {
            cout << "Current balance: $" 
                 << bankAccount.getBalance() << endl << endl;
            
            //If a full year has passed, ends the game
            if (dayNum == DAYS_IN_YEAR)
            {
                cout << "Your zoo has grown a lot in the past year!" << endl;
                cout << "Thanks for playing!" << endl << endl;
            }
            //If a full year has not yet passed, gives option to go to next day
            else
            {
                goToNextDay = gameMenu.continueGame();
            }
        }  
    }
}


/*********************************************************************
** Description: Void member function settingUpZoo is the first day of
**              the zoo. Asks the user if they would like to buy 1 or
**              2 of each animal. Subtracts the animal costs from the
**              user's money using Bank class.
*********************************************************************/
void Zoo::settingUpZoo()
{
    int initialTurtles,
        initialPenguins,
        initialTigers,
        initialNewAnimals,
        totalPriceTurtles,
        totalPricePenguins,
        totalPriceTigers,
        totalPriceNewAnimals;
    
    const int MIN_ANIMALS = 1,
              MAX_ANIMALS = 2,
              AGE = 1;

    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "You have finally saved up $" << bankAccount.getBalance() << endl
         << "and now you are fulfilling your dream to open a zoo!" << endl;
    cout << "The zoo's progress will be tracked for one year." << endl << endl;

    cout << "Now, let's buy some animals!" << endl;
    gameMenu.animalPrices();

    cout << endl << "Do you want to buy 1 or 2 turtles? Enter either 1 or 2: ";
    initialTurtles = validInput(MIN_ANIMALS, MAX_ANIMALS);

    //Adding turtle to zoo
    addTurtle(initialTurtles, AGE);
    cout << "Turtles added to your zoo: " << initialTurtles << endl;

    //Taking out cost for buying turtles
    totalPriceTurtles = initialTurtles * turtleList->getCost();
    bankAccount.withdrawMoney(totalPriceTurtles);


    cout << "Do you want to buy 1 or 2 penguins? Enter either 1 or 2: ";
    initialPenguins = validInput(MIN_ANIMALS, MAX_ANIMALS);

    //Adding penguin to zoo
    addPenguin(initialPenguins, AGE);
    cout << "Penguins added to your zoo: " << initialPenguins << endl;

    //Taking out cost for buying penguins
    totalPricePenguins = initialPenguins * penguinList->getCost();
    bankAccount.withdrawMoney(totalPricePenguins);


    cout << "Do you want to buy 1 or 2 tigers? Enter either 1 or 2: ";
    initialTigers = validInput(MIN_ANIMALS, MAX_ANIMALS);

    //Adding tiger to zoo
    addTiger(initialTigers, AGE);
    cout << "Tigers added to your zoo: " << initialTigers << endl;

    //Taking out cost for buying tigers
    totalPriceTigers = initialTigers * tigerList->getCost();
    bankAccount.withdrawMoney(totalPriceTigers);


    //Getting information about the new animal chosen by the user
    newAnimalList->pickNewAnimal();
    newAnimalName = newAnimalList->getName();

    cout << "For the " << newAnimalName
         << " species, do you want to buy 1 or 2? Enter either 1 or 2: ";
    initialNewAnimals = validInput(MIN_ANIMALS, MAX_ANIMALS);

    //Adding new animals to zoo; setting age
    addNewAnimal(initialNewAnimals, AGE);
    cout << numNewAnimals << " of the " 
         << newAnimalName << " species was added to your zoo." << endl;

    //Withdrawing money for new animals
    totalPriceNewAnimals = initialNewAnimals * newAnimalList->getCost();
    bankAccount.withdrawMoney(totalPriceNewAnimals);

    cout << "Current balance: $" << bankAccount.getBalance() <<endl << endl;
}


/*********************************************************************
** Description: Void member function animalAges takes in a pointer to
**              an Animal object array, the number of animals in a zoo
**              exhibit, a reference to the number of adult animals,
**              and a reference to the number of baby animals as
**              parameters. Increases each animal's age and counts
**              the number of adults and babies.
*********************************************************************/
void Zoo::ageAnimals(Animal *animals, int numAnimals, int &adults, int &babies)
{
    for (int i = 0; i < numAnimals; i++)
    {
        //Increase age of animal
        ++animals[i];

        //Counting number of adults/babies
        if (animals[i].isAdult())
        {
            adults++;
        }
        else
        {
            babies++;
        }
    }
}


/*********************************************************************
** Description: Private member function chooseFoodQuality calls
**              foodQuality function in Menu class to determine the
**              food animals should eat. Calculates the total cost and
**              subtracts from bank account. Returns an integer
**              representing the food chosen.
*********************************************************************/
int Zoo::chooseFoodQuality()
{
    int foodChoice;
    double turtleFood = 0,
           penguinFood = 0,
           tigerFood = 0,
           newAnimalFood = 0,
           total;

    //Show menu for food quality choices
    cout << "Time to feed the animals!" << endl;
    foodChoice = gameMenu.chooseFoodQuality();

    //Calculate food cost for each turtle
    for (int i = 0; i < numTurtles; i++)
    {
        turtleFood += turtleList->calculateFeedingCost(foodChoice);
    }
    cout << "Turtle food cost: " << turtleFood << endl;

    //Calculate food cost for each penguin
    for (int i = 0; i < numPenguins; i++)
    {
        penguinFood += penguinList->calculateFeedingCost(foodChoice);
    }
    cout << "Penguin food cost: " << penguinFood << endl;

    //Calculate food cost for each tiger
    for (int i = 0; i < numTigers; i++)
    {
        tigerFood += tigerList->calculateFeedingCost(foodChoice);
    }
    cout << "Tiger food cost: " << tigerFood << endl;

    //Calculate food cost for each new animal
    for (int i = 0; i < numNewAnimals; i++)
    {
        newAnimalFood += newAnimalList->calculateFeedingCost(foodChoice);
    }
    cout << newAnimalName << " food cost: " << newAnimalFood << endl;

    //Finding total food cost
    total = turtleFood + penguinFood + tigerFood + newAnimalFood;
    cout << "Total food cost: " << total << endl;
    bankAccount.withdrawMoney(total);

    return foodChoice;
}


/*********************************************************************
** Description: Void member function buyAnimal asks the user if they
**              want to buy an animal. Adds animal to the zoo if they
**              choose to buy an animal.
*********************************************************************/
void Zoo::buyAnimal()
{
    int newAnimalCost = newAnimalList->getCost();
    
    //Showing menu for prices of each animal
    int animal = gameMenu.purchaseAnimals(newAnimalName, newAnimalCost);

        //Buying a turtle
        if (animal == TURTLE)
        {
            cout << "One turtle has been added." << endl << endl;
            addTurtle();
            bankAccount.withdrawMoney(turtleList->getCost());
        }
        //Buying a 3 day old penguin
        else if (animal == PENGUIN)
        {
            cout << "One penguin has been added." << endl << endl;
            addPenguin();
            bankAccount.withdrawMoney(penguinList->getCost());
        }
        //Buying a 3 day old tiger
        else if (animal == TIGER)
        {
            cout << "One tiger has been added." << endl << endl;
            addTiger();
            bankAccount.withdrawMoney(tigerList->getCost());
        }
        //Buying a 3 day old new animal
        else if (animal == NEW_ANIM)
        {
            cout << "One " << newAnimalName << " has been added." << endl;
            addNewAnimal();
            newAnimalList[numNewAnimals - 1].setAge(3);
            bankAccount.withdrawMoney(newAnimalList->getCost());
        }
        //Not buying an animal
        else
        {
            cout << "You did not purchase a new animal." << endl << endl;
        }
}


/*********************************************************************
** Description: Member function animalProfits takes a pointer to an
**              Animal object array and an int for the number of 
**              animals as parameters. Returns the total amount of 
**              money earned for all the animals in an exhibit.
*********************************************************************/
double Zoo::animalProfits(Animal *animalArr, int numAnimals)
{
    double individualProfit,
           totalProfit = 0;

    //Totaling the profits made for each animal in the array
    for (int i = 0; i < numAnimals; i++)
    {
        individualProfit = animalArr->getPayoff();
        totalProfit += individualProfit;
    }

    return totalProfit;
}


/*********************************************************************
** Description: Private member function randomEvent takes an integer
**              representing the food quality as a parameter. A random
**              number is picked which determines what event function
**              occurs (sickness, attendance boom, animal born, or
**              no event). The food quality determines how likely an
**              animal is to get sick. If the is an attendance boom, 
**              returns the amount of bonus money. If not, returns 0.
*********************************************************************/
double Zoo::randomEvent(int foodQuality)
{
    int event,
        sickAnimal;
    double bonus = 0;
    
    //Generating random integer to determine what event should happen
    event = rand() % 24 + 1;

    //Sickness twice as likely if cheap food picked
    if (foodQuality == CHEAP)
    {
        if (event <= 12)
        {
            sicknessOccurs();
        }

        else if (event <= 16)
        {
            bonus = zooAttendanceBoom();
        }

        else if ( event <= 20)
        {
            babyAnimalBorn();
        }

        else
        {
            noEvent();
        } 
    }

    //Likeliness of animal getting sick is unchanged if generic food picked
    else if (foodQuality == GENERIC)
    {
        if (event <= 6)
        {
            sicknessOccurs();
        }

        else if (event <= 12)
        {
            bonus = zooAttendanceBoom();
        }

        else if (event <= 18)
        {
            babyAnimalBorn();
        }

        else
        {
            noEvent();
        } 
    }

    //Sickness is half as likely if premium food is picked
    else if (foodQuality == PREMIUM)
    {
        if (event <= 3)
        {
            sicknessOccurs();
        }

        else if (event <= 10)
        {
            bonus = zooAttendanceBoom();
        }

        else if (event <= 17)
        {
            babyAnimalBorn();
        }

        else
        {
            noEvent();
        } 
    }
    
    return bonus;
}


/*********************************************************************
** Description: Void private member function sicknessOccurs generates
**              a random number in order to determine which of the
**              animals gets sick. Takes out one animal of the 
**              randomly selected species.
*********************************************************************/
void Zoo::sicknessOccurs()
{
    int sickAnimal,
        totalSpecies = 4;

    string animalName;

    //Picking the animal that gets sick; randomly selects one of 3 species
    sickAnimal = rand() % totalSpecies + 1;

    //If a turtle gets sick
    if ((sickAnimal == 1) && numTurtles > 0)
    {
        animalName = "turtle";
        numTurtles--;
    }

    //If a penguin gets sick
    else if ((sickAnimal == 2) && numPenguins > 0)
    {
        animalName = "penguin";
        numPenguins--;
    }

    //If a tiger gets sick
    else if ((sickAnimal == 3) && numTigers > 0)
    {
        animalName = "tiger";
        numTigers--;
    }

    //If new animal gets sick
    else if ((sickAnimal == 4) && numNewAnimals > 0)
    {
        animalName = newAnimalName;
        numNewAnimals--;
    }

    //A different animal is chosen if there are no animals at the zoo for the
    //species chosen. Chosen species must have at least one member in the zoo
    else if (numTurtles > 0)
    {
        animalName = "turtle";
        numTurtles--;
    }

    else if (numPenguins > 0)
    {
        animalName = "penguin";
        numPenguins--;
    }

    else if (numTigers > 0)
    {
        animalName = "tiger";
        numTigers--;
    }

    else if (numNewAnimals > 0)
    {
        animalName = newAnimalName;
        numNewAnimals--;
    }

    cout << "Sadly, a " << animalName << " died due to sickness." << endl;
}


/*********************************************************************
** Description: Private member function zooAttendanceBoom picks a
**              random integer from 250 to 500 for a bonus made by 
**              tigers during one day at the zoo. Returns the bonus.
**              Source: https://stackoverflow.com/questions/12657962/
**              how-do-i-generate-a-random-number-between-two-
**              variables-that-i-have-stored
*********************************************************************/
double Zoo::zooAttendanceBoom()
{
    int bonusPerTiger;
    double totalBonus = 0;

    const int MIN_BONUS = 250,
              MAX_BONUS = 500;

    //Determining how much extra money is made
    bonusPerTiger = rand() % (MAX_BONUS - MIN_BONUS + 1) + MIN_BONUS;

    //The bonus is received for each tiger
    for (int i = 0; i < numTigers; i++)
    {
        totalBonus += bonusPerTiger;
    }

    cout << "There was a boom in attendance today!" << endl;
    cout << "You earned an extra $" << bonusPerTiger << " per tiger." << endl;
    cout << "Total bonus: $" << totalBonus << endl;
    
    return totalBonus;
}


/*********************************************************************
** Description: Void private member function babyAnimalBorn first
**              determines if an animal in each species is an adult.
**              If the random species selected contains an adult, then
**              the adult has babies. If not and there is another
**              species that has an adult, that adult has babies. If
**              there are no adults, no babies are born.
*********************************************************************/
void Zoo::babyAnimalBorn()
{
    bool adultTurtle = false,
         adultPenguin = false,
         adultTiger = false,
         adultNewAnimal = false;

    int totalSpecies,
        parentAnimal,
        babyAmount,
        babyAge = 0;

    string parentName;

    totalSpecies = 4;
    
    //Determining which species will have a baby
    parentAnimal = rand() % totalSpecies + 1;

    //Seeing if there are any adult turtles
    for (int i = 0; i < numTurtles; i++)
    {
        if (turtleList[i].isAdult())
        {
            adultTurtle = true;
        }
    }

    //Seeing if there are any adult penguins
    for (int i = 0; i < numPenguins; i++)
    {
        if (penguinList[i].isAdult())
        {
            adultPenguin = true;
        }
    }

    //Seeing if there are any adult tigers
    for (int i = 0; i < numTigers; i++)
    {
        if (tigerList[i].isAdult())
        {
            adultTiger = true;
        }
    }

    //Seeing if there are any adult new animals
    for (int i = 0; i < numNewAnimals; i++)
    {
        if (newAnimalList[i].isAdult())
        {
            adultNewAnimal = true;
        }
    }

    //If there is an adult animal
    if (adultTurtle || adultPenguin || adultTiger || adultNewAnimal)
    {
        //Turtle is randomly selected and there is an adult turtle
        if ((parentAnimal == 1) && (adultTurtle))
        {
            babyAmount = turtleList->getBabiesBorn();
            cout << "A turtle just had " << babyAmount << " babies!" << endl;
            addTurtle(babyAmount, babyAge);
        }

        //Penguin is randomly selected and there is an adult penguin
        else if ((parentAnimal == 2) && (adultPenguin))
        {
            babyAmount = penguinList->getBabiesBorn();
            cout << "A penguin just had " << babyAmount << " babies!" << endl;
            addPenguin(babyAmount, babyAge);
        }

        //Tiger is randomly selected and there is an adult tiger
        else if ((parentAnimal == 3) && (adultTiger))
        {
            babyAmount = tigerList->getBabiesBorn();
            cout << "A tiger just had " << babyAmount << " baby!" << endl;
            addTiger(babyAmount, babyAge);
        }

        //New animal is randomly selected to and there is an adult
        else if ((parentAnimal == 4) && (adultNewAnimal))
        {
            babyAmount = newAnimalList->getBabiesBorn();
            cout << "A " << newAnimalName << " just had " 
                 << babyAmount << " babies!" << endl;
            addNewAnimal(babyAmount, babyAge);
        }

        //The following statements will occur if the randomly selected animal
        //did not have an adult. Checks to see if others species have an adult
        else if (adultTurtle)
        {
            babyAmount = turtleList->getBabiesBorn();
            cout << "A turtle just had " << babyAmount << " babies!" << endl;
            addTurtle(babyAmount, babyAge);
        }

        else if (adultPenguin)
        {
            babyAmount = penguinList->getBabiesBorn();
            cout << "A penguin just had " << babyAmount << " babies!" << endl;
            addPenguin(babyAmount, babyAge);
        }

        else if (adultTiger)
        {
            babyAmount = tigerList->getBabiesBorn();
            cout << "A tiger just had " << babyAmount << " baby!" << endl;
            addTiger(babyAmount, babyAge);
        }

        else if (adultNewAnimal)
        {
            babyAmount = newAnimalList->getBabiesBorn();
            cout << "A " << newAnimalName << " just had " 
                 << babyAmount << " babies!" << endl;
            addNewAnimal(babyAmount, babyAge);
        }
    }

    //If all animals in zoo are babies
    else
    {
        cout << "All of the baby animals look healthy!" << endl;
        noEvent();
    }
}


/*********************************************************************
** Description: Void private member function noEvent prints that 
**              nothing happened at the zoo during the day.
*********************************************************************/
void Zoo::noEvent()
{
    cout << "Today was just an average day." << endl;
    cout << "Nothing particularly exciting happened." << endl;
}


/*********************************************************************
** Description: Void private member function addTurtle takes in the
**              number of turtles to be added and their age as
**              parameters. Default number added is 1, while default 
**              age is 3. Adds these turtles to the zoo. If the 
**              turtle exhibit is full, doubles its size.
*********************************************************************/
void Zoo::addTurtle(int numAdded, int age)
{
    int turtleAge;
    Turtle *doubleArray;

    numTurtles += numAdded;

    if (numTurtles >= maxTurtles)
    {
        maxTurtles *= 2;
        doubleArray = new Turtle[maxTurtles];

        for (int i = 0; i < numTurtles; i++)
        {
            //Putting new turtles added in larger exhibit
            if (i > ((numTurtles - 1) - numAdded))
            {
                doubleArray[i].setAge(age);
            }

            //Copying ages of turtles in old array into new array
            else
            {
                turtleAge = turtleList[i].getAge();
                doubleArray[i].setAge(turtleAge);
            }
        }

        delete [] turtleList;

        //New array of turtles is now created
        turtleList = doubleArray;
    }

    //Putting new turtles in exhibit if still room
    else
    {
        for (int i = 0; i < numTurtles; i++)
        {
            if (i > ((numTurtles - 1) - numAdded))
            {
                turtleList[i].setAge(age);
            }
        }
    }
}


/*********************************************************************
** Description: Void private member function addPenguin takes in the
**              number of penguins to be added and their age as 
**              parameters. Default number added is 1, while default
**              age is 3. Adds these penguins to the zoo. If the
**              penguin exhibit is full, doubles its size.
*********************************************************************/
void Zoo::addPenguin(int numAdded, int age)
{
    int penguinAge;
    Penguin *doubleArray;

    numPenguins += numAdded;

    //Doubling size if number added is over the penguin capacity
    if (numPenguins >= maxPenguins)
    {
        maxPenguins *= 2;
        doubleArray = new Penguin[maxPenguins];

        for (int i = 0; i < numPenguins; i++)
        {
            //Putting new penguins added in larger exhibit
            if (i > ((numPenguins - 1) - numAdded))
            {
                doubleArray[i].setAge(age);
            }

            //Copying ages of penguins in old array into new array
            else
            {
                penguinAge = penguinList[i].getAge();
                doubleArray[i].setAge(penguinAge);
            }
        }

        delete [] penguinList;

        //New array of penguins is now created
        penguinList = doubleArray;
    }

    //Putting new penguins in exhibit if still room
    else
    {
        for (int i = 0; i < numPenguins; i++)
        {
            if (i > ((numPenguins - 1) - numAdded))
            {
                penguinList[i].setAge(age);
            }
        }
    }
}


/*********************************************************************
** Description: Void private member function addTiger takes in the 
**              number of tigers to be added and their age as 
**              parameters. Default number added is 1, while default 
**              age is 3. Adds these tigers to the zoo. If the tiger
**              exhibit is full, doubles its size.
*********************************************************************/
void Zoo::addTiger(int numAdded, int age)
{
    int tigerAge;
    Tiger *doubleArray;

    numTigers += numAdded;

    //Doubling size if number added is over the tiger capacity
    if (numTigers >= maxTigers)
    {
        maxTigers *= 2;
        doubleArray = new Tiger[maxTigers];

        for (int i = 0; i < numTigers; i++)
        {
            //Putting new tigers added in larger exhibit
            if (i > ((numTigers - 1) - numAdded))
            {
                doubleArray[i].setAge(age);
            }

            //Copying ages of tigers in old array into new array
            else
            {
                tigerAge = tigerList[i].getAge();
                doubleArray[i].setAge(tigerAge);
            }
        }

        delete [] tigerList;

        //New array of tigers is now created
        tigerList = doubleArray;
    }

    //Putting newtigers in exhibit if still room
    else
    {
        for (int i = 0; i < numTigers; i++)
        {
            if (i > ((numTigers - 1) - numAdded))
            {
                tigerList[i].setAge(age);
            }
        }
    }
}


/***********************************************************************
** Description: Void private member function addNewAnimal takes the
**              number of new animals added and their age as parameters.
**              Default number added is 1, while default age is 3.
**              Adds new animals to the zoo. Doubles array if no room.
***********************************************************************/
void Zoo::addNewAnimal(int numAdded, int age)
{
    NewAnimal *doubleArray,
              animal;

    numNewAnimals += numAdded;

    //Doubling size if number added is over the new animal capacity
    if (numNewAnimals >= maxNewAnimals)
    {
        maxNewAnimals *= 2;
        doubleArray = new NewAnimal[maxNewAnimals];

        for (int i = 0; i < numNewAnimals; i++)
        {
            //Putting new animals added in larger exhibit
            if (i > ((numNewAnimals - 1) - numAdded))
            {
                doubleArray[i].setAge(age);
            }

            //Copying ages of new animal in old array into new array
            else
            {
                animal = newAnimalList[i];
                doubleArray[i] = animal;
            }
        }

        delete [] newAnimalList;

        //New array of new animals is now created
        newAnimalList = doubleArray;
    }

    //Putting new animal in exhibit if still room
    else
    {
        for (int i = 0; i < numNewAnimals; i++)
        {
            if (i > ((numNewAnimals - 1) - numAdded))
            {
                newAnimalList[i].setAge(age);
            }
        }
    }
}


/*********************************************************************
** Description: Destructor for the Zoo class that deletes dynamically
**              allocated memory.
*********************************************************************/
Zoo::~Zoo()
{
    delete [] turtleList;
    delete [] penguinList;
    delete [] tigerList;
    delete [] newAnimalList;
}