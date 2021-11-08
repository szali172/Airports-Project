# CS 225 Data Structures

# Team Proposal (ai10-sali200-drugutt2-priyak5)

## Leading Question

The goal of the project is to help individuals understand 
the relationship and similarities/differences of music interests 
between two users/datasets. We are interested in being able to 
let individuals better understand their music taste through 
different metrics based on their listening history and musical 
interests and being able to calculate not only how similar two 
individuals music tastes are similar, but being able to recommend 
different songs, artists, albums, and more based on these 
similarities/differences and being able to recommend songs that 
they both would enjoy.

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
[NEED STUFF HERE]
***
### Week 2 (Nov 15th - Nov 19th):
[NEED STUFF HERE]
*** 
### Week 3 (THANKSGIVING BREAK):
[NEED STUFF HERE]
*** 
### Week 4 (Nov 29th - Dec 3rd) [Mid-Project Check-in from Nov 29th - Dec 1st]:
[NEED STUFF HERE]
*** 
### Week 5 (Dec 6th - Dec 10th, Dec 13th) [FINAL WEEK]:
[NEED STUFF HERE]

