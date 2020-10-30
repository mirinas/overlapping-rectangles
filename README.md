# overlapping-rectangles
 C++ script for mapping out given rectangles that may or may not overlap

 Given example data:

    300 300             //max dimensions
    7                   //number of rectangles

                        //dimensions of rectangles (bottom left and top right corners)
    24 70 120 150
    50 200 100 280
    100 0 210 150
    50 70 120 280
    120 70 250 150
    250 280 300 300  
    50 0 120 70

Output - table with numbers of layers in all positions:

    0 0 0 0 0 0 1
    0 0 2 1 0 0 0
    0 0 1 1 0 0 0
    0 1 2 3 2 1 0
    0 0 1 2 1 0 0


 Script creates a table, that includes every size used by given rectangles, then fills it up. Here is a visualisation to how this script works:

 <img width = "900" alt = "filled table" src=“img/grid.png” raw=true>
 
[![grid](img/grid.png)
