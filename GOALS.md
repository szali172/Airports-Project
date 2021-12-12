# CS 225 Data Structures

# Team Proposal (ai10-sali200-drugutt2-priyak5)

## Leading Question
Given a source airport, what is the shortest path between every airport in the world and the source airport?

## Dataset Acquisition and Processing
We will use the OpenFlights airport dataset provided. Our data will be downloaded as CSVs and uploaded directly into GitHub and pulled into VSCode. There are two CSV files from this dataset that we will use. 
One of them holds data on the airports (airports.dat) which will be used to create our vertex list in our graph implementation. We will parse through each line of this CSV file and only use each airport’s ID, longitude, latitude, source airport ID, and destination airport ID. We will be using an adjacency list to represent our graph. The graph will be weighted and directed and will represent all airports and all of their connections. Each vertex represents an airport. Since the airports all have unique IDs in the CSV in increasing order from 1-14,110, each adjacency list index will correspond to an airport ID (e.g. if we want to find an airport with ID 1126, vertex_list.get(1126)).
The second CSV we are using will be the routes between each airport (routes.dat). These routes will tell us which airports have which connections. The CSV lines contain a source airport and a destination airport, representing a to-and-from relationship. This means our edges will naturally be a directed relationship from airport to airport. Some airports will be directed one way, but most connections will be bi-directional. 
Using the longitude and latitude from each connected airport, we can calculate the distance between the two. This distance will become the weight of the edge connecting the two airports. The list at the current element (airport) in the adjacency list will hold a list of all of its neighboring airports (its connections). This list of neighboring airports will hold pairs as well as a pointer to the next linked neighbor. The first element of the pair will hold the airport ID of the current neighbor in the list. The second element of the pair will hold the distance between the current airport in the adjacency list and the current neighbor.
If we need to retrieve any other information about the airport such as the airport’s name, IATA Code, etc., we can look up the airport in the CSV using its given index (its airport ID). The Airport IDs greatly decrease the runtime of our search algorithms such as areAdjacent because there will be constant time to retrieve an airport and its linked edge list.

Note: The data set begins the unique IDs with 1 instead of 0. To keep it consistent, we can use index 0 of the vertex list to store information about the entire graph if need be (size, max degrees, etc.), otherwise it can be left empty so the first airport can begin at index 1. This will also eliminate potential errors when retrieving airports.

## Graph Algorithms
The first algorithm (covered) we will use is Dijkstra’s algorithm. The first input will be the adjacency list created from processing the CSVs with its vertices representing every airport in the world and its edges representing the routes between them. Edge weights will hold the distance between two airports. The second input will be a source airport chosen by the user. The default will be O’Hare/ORD. 
The output we are expecting for this algorithm is a shortest path tree showing the shortest path from the source airport to every other airport in the world (for every airport in the world). Since our graph is directed, Dijkstra’s has to be used over a minimum spanning tree algorithm such as Prim’s or Kruskal’s. Our target Big-O is O(n(log(n)) + m(log(n))).
Note: When a user inputs an airport, it is unlikely that they will know the airport ID of the airport they are looking for. Therefore, we have to search through the CSV for their passed string, whether it be an IATA code or the airport name. Once we find the string, we can retrieve that airport ID and begin Dijkstra’s with that as the starting/source node. If the user inputs a string that does not match or the value does not exist, we can throw an error message. Parsing through the CSV to find our starting airport will be an additional runtime of O(n).
The second algorithm (uncovered) will be the graphic output of a graph. This algorithm will overlay all the airport connections that solve the leading question (our output from Dijkstra’s algorithm) onto a PNG. We can scale the image height and image width to the range of latitude and longitude. Since we have the coordinates for every airport and the distances between every connected airport, we can draw points (nodes of Dijkstra’s shortest path tree) and lines (edges from that tree) onto our PNG.
The input will be our SSSP graph (the shortest path tree) outputted by Dijkstra’s algorithm. DFS will take care of the ordering in which vertices and edges are visited. The output will be a new PNG which contains our original map PNG with the overlaid airports and distances in a different color. The target Big-O is O(|V| + |E|) of the SSSP graph because we will traverse every vertex and edge in the SSSP graph.
Here is some of the logic behind scaling our coordinates to fit in the constraints of our base PNG:
-90 <= latitude <= 90 , -180 <= longitude <= 180
0 <= PNG.height() < 2500 , 0 <= PNG.width() < 5000
### For Drawing the airports (vertexes)
Formula for latitude: 
pixel.y = image.height/2 - (image.height/2) / 90 * abs(latitude)
Formula for longitude:
pixel.x = image.width/2 - (image.width/2) / 180 * abs(longitude)
Then we can round the double result into an integer
If the latitude is positive, pixel.y
If latitude negative, image.height - pixel.y
If longitude is positive, image.width - pixel.x
If longitude is negative, pixel.x
### For drawing travels between airports (edges)
Given two points, find the slope of the line using the difference between their x coordinates and y coordinates, draw the line as the loop walks from point A to point B. We can check the direction in which x and y need to walk by comparing if x coordinate for point A is > or < point B x coordinate. Same for their y coordinates respectively.

## Graph traversal: DFS
We will use DFS to traverse the graph (the shortest path tree outputted by Dijkstra’s algorithm) and project it onto the map. The root node of the SSSP will be the starting/source airport.

## Timeline
### Week 1 (Nov 8th - Nov 12th):
Work on correcting proposal.
***
### Week 2 (Nov 15th - Nov 19th):
We will experiment with the data and implement our dataset within C++. We will test to make sure the input and output works with a very basic test case, and we will start implementing our graph traversal along with possible our graph data algorithms
***
### Week 3 (THANKSGIVING BREAK):
Relax.
***
### Week 4 (Nov 29th - Dec 3rd) [Mid-Project Check-in from Nov 29th - Dec 1st]:
We will process all of our data as described and begin work on our graph data algorithms. During this time we will also focus on creating test cases and ensuring that our analysis is not manipulating our current database.
***
### Week 5 (Dec 6th - Dec 10th, Dec 13th) [FINAL WEEK]:
Final clean up with our algorithms and also finalizing/passing our test cases.
