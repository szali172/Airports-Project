# CS 225 Data Structures

# Team Proposal (ai10-sali200-drugutt2-priyak5)

## Leading Question

The goal of the project is to curate a new playlist for a Spotify 
user based on their current favorite artists and the genres they are known for. 
We are interested in helping the user find new songs in 
a music taste that is still familiar to them.

## Dataset Acquisition and Processing

We will be extracting data from Spotify using the Spotify API and a 
combination of the the SpotiPy Python library 
(https://spotipy.readthedocs.io/en/2.19.0/) and the SpotifyR R package 
(https://github.com/charlie86/spotifyr) to extract the information 
about songs, albums, artists, and more from a proposed user. We will then 
map a specific track to nodes that will have linking edges to their 
position/existence in a playlist, album, artist, or genre (for example, 
a track will link to an artist, which will link to a genre). We will then 
be able to map the variety of songs between two different databases 
(users/people), and we will be able to do analysis on them such as including 
an edge between two songs, artists, or an album based on if there is a 
recommendation from one to the other (through parameters like the energy, 
valence, emotion, and more of a song, album, or artist).
Also, because we are getting data from the Spotify API services, it is very 
unlikely that there will be missing information from every track as all the 
information is verified directly from Spotify (we should not run into any 
real-world data that will contain errors). 

## Graph Algorithms

Our main data structure will be an Adjacency List implementation. The algorithm we will be using that was covered in class will be Dijkstra’s algorithm. This will be used to find the closest connections between artists in the user’s playlist and Spotify’s curated genre playlists. The algorithm we will be using that was not covered in class will be the PageRank algorithm. This will be used to give the user’s most favorite artists higher rank and their less favorite artists lower rank. We will be using a depth-first traversal to traverse the data in the graph. We will be looking at one Spotify user’s list of most favorite artists. As input, we will be taking in an integer representing the weight (genre) we are looking for in the top favorite artists list. The output will be a set of new songs for the user to listen to.

## Timeline

### Week 1 (Nov 8th - Nov 12th):
We will get familiar with the Spotify API and get a working database through the SpotiPy/SpotifyR packages/libraries. We will make sure to clean up the database and create working demos for the final product.
***
### Week 2 (Nov 15th - Nov 19th):
We will experiment with the data and implement our dataset within C++. We will test to make sure the input and output works with a very basic test case, and we will start implementing our graph traversal along with possible our graph data algotirhms
*** 
### Week 3 (THANKSGIVING BREAK):
Relax.
*** 
### Week 4 (Nov 29th - Dec 3rd) [Mid-Project Check-in from Nov 29th - Dec 1st]:
We will continue working on our graph data algorithms and ensuring that the comparisons between the 2+ datasets are working as expected. During this time we will also focus on creating test cases and ensuring that our analysis is not breaking the functionality or manipulating our current database.
*** 
### Week 5 (Dec 6th - Dec 10th, Dec 13th) [FINAL WEEK]:
Final clean up with our algorithms and also finalizing our test cases.

