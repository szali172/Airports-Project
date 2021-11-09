# CS 225 Data Structures

# Team Proposal (ai10-sali200-drugutt2-priyak5)

## Leading Question

The goal of the project is to help individuals understand 
the similarities in music interests 
between two users/datasets. We want to do this by calculating 
different metrics based on their listening history and musical 
interests. We want to calculate not only how two 
users' music tastes are similar, but also make them able to recommend 
different songs, artists, and albums based on these 
similarities.

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
valence, emotion, and more of a song, album, or artist). Because we will 
be using algorithms that don’t care about weights, we will not need them. 
Also, because we are getting data from the Spotify API services, it is very 
unlikely that there will be missing information from every track as all the 
information is verified directly from Spotify (we should not run into any 
real-world data that will contain errors). 

## Graph Algorithms

[NEED STUFF HERE]

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

