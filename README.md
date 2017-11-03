# Viagogo Coding Challenge

The assumptions that I have made:
1. Some events can have the same coordinates
2. All coordinates have 1 event
3. The coordinates will be whole numbers and not decimals, as well as the distance
4. If a coordinate is found to be larger than 10, then it is made to be equal to 10
5. If a coordinate is found to be smaller than -10, then it is made to be equal to -10
6. The user will follow instructions and not input values greater than 10 or smaller than -10 for the coordinates
7. The price of the tickets is of type int

# Questions
1. How might you change your program if you needed to support multiple events at the
same location?

If I needed to support multiple events at the same location, then in my Coordinate constructor, I would pass a vector of type Event. This would then enable a single Coordinate to support multiple events. The Event constructor would no longer accept a Coordinate object as an argument. 


2. How would you change your program if you were working with a much larger world
size?

I would modify my code so that it would be more precise in the sense where the x and y coordinates as well as the price of the tickets are allowed to be decimal (i.e. double). I would have multiple constructors in the Coordinate class so that there would be an option for a Coordinate to have no events. 

