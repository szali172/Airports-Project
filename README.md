*This project was completed as part of the CS 225 course at University of Illinois Urbana-Champaign as our group's final project. I worked as the Senior Developer of the project, coding a large portion of the codebase, setting up the structure, writing the make file, splitting up and delegating tasks, and overseeing the production.*

# CS 225 Data Structures

# README File (ai10-sali200-drugutt2-priyak5)

# Authors
+ Zuhair Ali - sali200@illinois.edu
+ Lexi Ippolito - ai10@illinois.edu

+ Daniel Rugutt - drugutt2@illinois.edu
+ Priya Kumar - priyak5@illinois.edu

## Summary

The question our group answered with our project is:

*Given a source airport, what is the shortest path between every airport in the world and the source airport?*

To answer this question, we used the OpenFlights airport dataset to get a list of every single airport in the world along with every single possible route possible to perform data analysis to figure out this problem. These files hold a lot of extraneous information like the airport's name, IATA Codes, etc..., but the main piece of information which will be used to solve the question from both files is the current airport ID, longitude, latitude, source airport ID, and the destination airport ID. This project uses an adjacency list (processed from both CSV files) to represent the graph of possible weighted and direction connections of all the airports, where the vertex represents and airport and the edges represents the possible routes/connections between each airport (representing a to-and-from bi-directional relationship). To perform the data analysis to solve the question, this project implements a Dijkstra's algorithm (covered algorithm) to examen the adjacency list to find the shortest path between two distinct airports for every airport in the world and the source airport (through an inpurt of the airport name or unique OpenFlights airport ID). The project will then display the results graphically from the results of the Dijkstra's algorithm onto a PNG (uncovered algorithm). Finally the DFS will cover the ordering of which the verticies and edges are visited (graph traversal).


## Data Cleaning

The main two problems faced when working with the OpenFlights data with the list of airports and possible routes is how to properly access it within the C++ code and how to ensure that the airports are stored in the correct position to be easily accessed. Because the final project is using the input stream class to parse through the dataset (a way to operate on files), it was not originally feasible to parse through the data set using a .dat file. The way to fix this first problem was to convert both .dat files into csv through Python, specifically using Pandas to help with the data conversion and manipulation. The second problem faced was the fact that the airport IDs within the airports.csv (previously airports.dat) was not in sequentual numerical order, as the airport ID's would sometimes skip number, which was initially troublesome to overcome this issue when implementing the adjacency list. To combat this the group first tried to use Pandas to change all the airport IDs to be in numerical order (The only .py code used for this can be found within the data folder under, "change_airport_id.py"). The group later realized how this would interfere with the routes.csv (previously routes.dat) file as that file used the same airport IDs. To finally overcome this problem, in the adjacency list, if the next airport ID is not sequentially in order from the previous airport ID, null vertexes are inputed within the adjacency list until it is numerically sequential, which will help make the adjacency list accesses more feasible, accessible, and consistent with both the airports.csv and routes.csv file.


## The linkage location of all major code, data, and results

The main source code is located within the *__parse-dijkstra__* and *__visual-dfs__* folders. 

The *__parse-dijkstra__* folder contains the main Dijkstra graph algorithm, specifically within the *src* folder with the graph-parse.cpp and graph.cpp which has the implementations, the definitions of each method are located within the *include* folder, and the test cases are located within the *tests* folder.

The *__visual-dfs__* folder contains the main DFS search and the PNG algorithms used to properly visualize the OpenFlights dataset and the distance between any two airports within the world. Like the *__parse-dijkstra__* folder, the main implementations of the PNG, HSLAPixel, and visual classes when visualizing the parsed data is located within the *src* folder, the definitions of each method are located within the *include* folder, and the test cases are located within the *tests* folder.

The *__data__* folder contains the main dataset the project uses, specifically *airports.csv*, *routes.csv*, and *base_map.png*. This folder also contains the *change_airport_id.py* file used to clean the dataset (it is not used in the compilation or execution of the final project).

Every .h file within the *include* folder in both the *__parse-dijkstra__* and the *__visual-dfs__* folders contain .h header files which contains detailed descriptions of each method/function, constructor, and variables used, which can also be taken to create a Doxygen on your own machine given the right installation setup (steps not shown in this README).


## Getting Started

To get this project running and successfully compiled on your machine, follow these steps below:

### Prerequisites and Installation

We reccommend you run this project on the University EWS system such as through SSH or FastX. There are other alternative methods to run this project on your machine such as locally with a VM or working natively, although each method comes with its pros and cons. For instructions on how to set this up, follow the instructions on the CS 225 course website [here](https://courses.engr.illinois.edu/cs225/fa2021/resources/own-machine/)

*Note, you will need at the minimum __Git__ (software for GitHub), (perferrably) __VSCode__, __C++__ (and it's reccomended/external packages), __Clang__, and a stable connection to the UIUC EWS Workstations.*

Once everything is set up, you can clone the repository by running the following command in your perferred enditor/terminal workspace

```
$ git clone https://github.com/szali172/Airports-Project.git
```


## Instructions on how to build and run the executable

First, you will need to build all the dependencies and the Makefile.

```
$ cmake3 .
```
Followed by
```
$ make
```

Once it successfully compiles, you can then run the program and generate the visualizations with the command below:

```
$ src/main
/* This automatically grabs all the files listed below, and will output a completed picture called "dijkstra_picture.png in the main file structure */
```
+ `Airport Data Location` : The file location of the airports dataset. The data set is found in the main project folder at "data/airports.csv"
+ `Route Data Location` : The file location of the routes dataset. The data can be found at "data/routes.csv
+" `Source Airport` : The OpenFlights unique identified for the starting airport, i.e. "ORD"
+ `Destination Airport` : The OpenFlights unique identified for the ending airport, i.e. "NBO"
+ `Image Location` : The desired output location for the PNG file (must end in .png), i.e. "data/base_map.png"

After running the commnd above, you may see in the console if any inputs were invalid, or if the arguments were successfully inputed, the correct output of the program


## Project Demo

This is the result of running the main makefile:

![output](https://github.com/szali172/Airports-Project/blob/Zuhair/output.png)
  
## Instructions on how to build and run the test suites

The way to run the test cases are very similar to how to build and run the main executable for the program. 

To run the test cases for the final_project, you need to first build the executable and ensure that the code compiles properly. There are three separate test cases you can test for each main component of the program, running the Dijkstra's algorithm, testing the parsing methods of the CSV file for the correct implementation of the adjacency lists (DFS algorithm), and testing out the PNG output of the graph traversal. Here are the three separate commands you can run to test each component:

```
$ make ./test
/* This runs all 3 tests, dijkstra's, parsing, and print/visual tests */
```

Once it successfully compiles, you can then run the program and generate the visualizations with the command below:

```
$ ./[specific test executable ran, i.e. "test-dijstra"] [Airport Data Location] [Route Data Location] [Source Airport] [Destination Airport] [Image Location]
```
+ `Airport Data Location` : The file location of the airports dataset. The data set is found in the main project folder at data/airports.csv
+ `Route Data Location` : The file location of the routes dataset. The data can be found at data/routes.csv
+ `Source Airport` : The OpenFlights unique identified for the starting airport
+ `Destination Airport` : The OpenFlights unique identified for the ending airport
+ `Image Location` : The desired output location for the PNG file (must end in .png)

After running the commnd above, you may see in the console if any inputs were invalid, or if the arguments were successfully inputed, the correct output of the program. You will also be able to see the Catch2 results of the test cases that are provided.

### Instructions/Examples of reproducing the tests (Test Demo)

This is the result of running the test cases makefile:


## Acknowledgements
+ This project was created as a final project for [CS 225](https://courses.engr.illinois.edu/cs225/fa2021/pages/final_project.html)
+ The flight data was taken from [OpenFlights](https://openflights.org/data.html)
