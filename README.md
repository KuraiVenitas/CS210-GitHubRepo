# MyRepository

Programming Languages CS-210: Project 3 | SNHU
=========================================================

The goal of this project was to create a program that would take in a list of items purchased within a grocery store and output the data in more manageable formats. 
This data would then be used to provide more data for how the store should reorganize its items, with those that are purchased more frequently placed in more convenient locations.

The functions of the program include: 
- Searching for an item via name
- Show all items and the amount purchased
- Show a histogram of all items purchased
- Exit Program

I felt I did well in keeping clean and organized code, in addition to creating a UI that doesn't get overly cluttered throughout its use. 
Exception handling and invalid input is also done fairly well, with one potential snag.
- When the user inputs an item to search for, if any letter after the 1st is capitalized, it won't find the item.
- I've workshoped a solution which is to change all items and the user's input to uppercase. Searching for the item then shouldn't be an issue.
- Something I also forgot to include was to delete the objects and free up the memory that was allocated to them. Considering it's best practice to do this, it's something I should've included.

An additional enhancement for the program would be to give the user the option to feed a text file into it, allowing it to be used more dynamically.
Ex: "Would you like to feed a text file?" 
If so, the user selects yes and types out the name of the file, which would already have the information necessary within it. 
The program would then use the new file for its data.

A major snag for myself was when creating new item objects.
Initially, I used a for loop to iterate through every item within items vector. 
While the concept does work, my execution was flawed, since I was attempting to create a new object within the loop.
I was met with error until I decicded to use a boolean value, isFound, to determine when a new object needed to be created.

When deciding which project to upload to my portfolio, I chose this one since it somewhat encapsulated all the lessons I've learned throughout the course, all of which are valuable skills that are transferable to other projects.
This is especially apprent when looking into C++ programming within Unreal Engine 4/5. 
The structure of the code is very similar, with the main difference being the libraries referenced and the syntax associated with them.

Thinking back on this program and there are a few solutions to make it maintainable, readable and adaptable:
- Maintainable: Keep the program within its intended scope and scale. If the program doesn't need to be any more complex, then do not make it so. The less to keep track of the better.
- Readable: Use proper spacing between lines where appropriate and ensure it is well commented, especially in areas that could potentially bring about confusion.
- Adaptable: Come up with or receive potential features that would give the program a greater need for its use, like as mentioned above. If the user has data to input and is given the option to do so, the program can be used more practically.


