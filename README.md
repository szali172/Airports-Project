# CS 225 Data Structures

# README File (ai10-sali200-drugutt2-priyak5)

# Authors
+ Zuhair Ali - sali200@illinois.edu
+ Lexi Ippolito - ai10@illinois.edu
+ Daniel Rugutt - drugutt2@illinois.edu
+ Priya Kumar - priyak5@illinois.edu

## Link to YouTube Video Demo: //Link Here

## Summary

The question our group answered with our project is:

*Given a source airport, what is the shortest path between every airport in the world and the source airport?*

To answer this question, we used the OpenFlights airport dataset to get a list of every single airport in the world along with every single possible route possible to perform data analysis to figure out this problem. These files hold a lot of extraneous information like the airport's name, IATA Codes, etc..., but the main piece of information which will be used to solve the question from both files is the current airport ID, longitude, latitude, source airport ID, and the destination airport ID. This project uses an adjacency list (processed from both CSV files) to represent the graph of possible weighted and direction connections of all the airports, where the vertex represents and airport and the edges represents the possible routes/connections between each airport (representing a to-and-from bi-directional relationship). To perform the data analysis to solve the question, this project implements a Dijkstra's algorithm (covered algorithm) to examen the adjacency list to find the shortest path between two distinct airports for every airport in the world and the source airport (through an inpurt of the airport name or unique OpenFlights airport ID). The project will then display the results graphically from the results of the Dijkstra's algorithm onto a PNG (uncovered algorithm). Finally the DFS will cover the ordering of which the verticies and edges are visited (graph traversal).


## Data Cleaning

The main two problems faced when working with the OpenFlights data with the list of airports and possible routes is how to properly access it within the C++ code and how to ensure that the airports are stored in the correct position to be easily accessed. Because the final project is using the input stream class to parse through the dataset (a way to operate on files), it was not originally feasible to parse through the data set using a .dat file. The way to fix this first problem was to convert both .dat files into csv through Python, specifically using Pandas to help with the data conversion and manipulation. The second problem faced was the fact that the airport IDs within the airports.csv (previously airports.dat) was not in sequentual numerical order, as the airport ID's would sometimes skip number, which was initially troublesome to overcome this issue when implementing the adjacency list. To combat this the group first tried to use Pandas to change all the airport IDs to be in numerical order (The only .py code used for this can be found within the data folder under, "change_airport_id.py"). The group later realized how this would interfere with the routes.csv (previously routes.dat) file as that file used the same airport IDs. To finally overcome this problem, in the adjacency list, if the next airport ID is not sequentially in order from the previous airport ID, null vertexes are inputed within the adjacency list until it is numerically sequential, which will help make the adjacency list accesses more feasible, accessible, and consistent with both the airports.csv and routes.csv file.


## The linkage location of all major code, data, and results

TODO FINISH THIS

Mauris vel turpis gravida, varius purus quis, pellentesque odio. Interdum et malesuada fames ac ante ipsum primis in faucibus. Sed tristique, neque dictum dignissim sodales, lectus metus tempor mauris, sed auctor mi leo varius sem. Etiam ut scelerisque neque, ut convallis ex. Aenean tellus dui, ultricies non ipsum ut, fringilla rutrum felis. Ut id volutpat dolor, imperdiet lobortis sem. Vivamus id turpis mollis nibh porta consectetur. Pellentesque nec enim vitae leo dignissim imperdiet at in dui. Donec dapibus maximus justo. Mauris consequat rhoncus nunc et malesuada. Pellentesque feugiat sapien commodo molestie varius. Sed nec arcu eget eros sollicitudin bibendum id vitae ligula.

### Definitions of the input and output location for each method:

TODO FINISH THIS

Etiam dignissim scelerisque sapien, faucibus lacinia felis gravida id. Nunc porta venenatis massa, quis ullamcorper nisi venenatis non. Maecenas mattis rhoncus ex, non tempor nunc tempus vel. Praesent quis diam et diam venenatis hendrerit at ac neque. Curabitur odio quam, fermentum quis fermentum et, auctor vel arcu. Proin sollicitudin placerat neque, id iaculis lorem scelerisque ut. Fusce fringilla eu mauris eget vehicula. Proin pellentesque, metus sit amet malesuada lacinia, massa tortor rhoncus ipsum, ac rutrum arcu risus ac mi. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Integer et faucibus urna. Suspendisse gravida ante nisi, volutpat ultrices lorem egestas eu. Quisque sit amet neque vitae dui accumsan lacinia ut sed dolor. Nunc aliquet sit amet dui at porta.


## Getting Started

To get this project running and successfully compiled on your machine, follow these steps below:

### Prerequisites and Installation

We reccommend you run this project on the University EWS system such as through SSH or FastX. There are other alternative methods to run this project on your machine such as locally with a VM or working natively, although each method comes with its pros and cons. For instructions on how to set this up, follow the instructions on the CS 225 course website [here](https://courses.engr.illinois.edu/cs225/fa2021/resources/own-machine/)

*Note, you will need at the minimum __Git__ (software for GitHub), (perferrably) __VSCode__, __C++__ (and it's reccomended/external packages), __Clang__, and a stable connection to the UIUC EWS Workstations.*

Once everything is set up, you can clone the repository by running the following command in your perferred enditor/terminal workspace

```
git clone https://github-dev.cs.illinois.edu/cs225-fa21/ai10-sali200-drugutt2-priyak5.git
```


## Instructions on how to build and run the executable

First, you will need to build all the dependencies and the Makefile.

```
cmake3 .
```
Followed by
```
make
```

Once it successfully compiles, you can then run the program and generate the visualizations with the command below:

```
src/main [Airport Data Location] [Route Data Location] [Source Airport] [Destination Airport] [Image Location]
```
+ `Airport Data Location` : The file location of the airports dataset. The data set is found in the main project folder at data/airports.csv
+ `Route Data Location` : The file location of the routes dataset. The data can be found at data/routes.csv
+ `Source Airport` : The OpenFlights unique identified for the starting airport
+ `Destination Airport` : The OpenFlights unique identified for the ending airport
+ `Image Location` : The desired output location for the PNG file (must end in .png)

After running the commnd above, you may see in the console if any inputs were invalid, or if the arguments were successfully inputed, the correct output of the program


## Project Demo

THIS IS THE PROJET DEMO - TODO FINISH THIS

Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?
  
## Instructions on how to build and run the test suites

The way to run the test cases are very similar to how to build and run the main executable for the program. 

To run the test cases for the final_project, you need to first build the executable and ensure that the code compiles properly. There are three separate test cases you can test for each main component of the program, running the Dijkstra's algorithm, testing the parsing methods of the CSV file for the correct implementation of the adjacency lists (DFS algorithm), and testing out the PNG output of the graph traversal. Here are the three separate commands you can run to test each component:

```
make test-dijstra
```
```
make test-parse
```
```
make test-print
```

Once it successfully compiles, you can then run the program and generate the visualizations with the command below:

```
./[specific test executable ran, i.e. "test-dijstra"] [Airport Data Location] [Route Data Location] [Source Airport] [Destination Airport] [Image Location]
```
+ `Airport Data Location` : The file location of the airports dataset. The data set is found in the main project folder at data/airports.csv
+ `Route Data Location` : The file location of the routes dataset. The data can be found at data/routes.csv
+ `Source Airport` : The OpenFlights unique identified for the starting airport
+ `Destination Airport` : The OpenFlights unique identified for the ending airport
+ `Image Location` : The desired output location for the PNG file (must end in .png)

After running the commnd above, you may see in the console if any inputs were invalid, or if the arguments were successfully inputed, the correct output of the program. You will also be able to see the Catch2 results of the test cases that are provided.

### Instructions/Examples of reproducing the tests (Test Demo)

TODO FINISH THIS

Etiam in posuere elit. Vivamus porta luctus orci, ac dictum ex vestibulum id. Nam ac tempor nunc. Fusce condimentum, magna et ornare ultricies, sapien augue cursus nibh, non vehicula eros ligula a odio. Nam justo ex, facilisis nec efficitur vel, aliquet in dolor. Morbi sagittis nibh nec metus iaculis, nec sodales sem dignissim. Nulla lobortis, quam sit amet molestie laoreet, felis leo pellentesque mauris, vel posuere augue ligula id elit. Quisque fermentum sit amet sapien aliquam pretium. Duis augue nulla, rutrum a maximus nec, euismod gravida purus. Maecenas sodales mi et ligula iaculis accumsan. Ut auctor commodo lorem, ac finibus augue feugiat ut. Sed et urna suscipit, molestie justo eget, lacinia elit. Nunc vel leo pellentesque, dapibus dolor id, consectetur lorem. Nam eleifend cursus velit, at mollis leo rutrum vitae.


## Acknowledgements
+ This project was created as a final project for [CS 225](https://courses.engr.illinois.edu/cs225/fa2021/pages/final_project.html)
+ The flight data was taken from [OpenFlights](https://openflights.org/data.html)
