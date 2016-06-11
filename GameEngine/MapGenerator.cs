using UnityEngine;
using System.Collections;
using System;

public class MapGenerator:MonoBehaviour
{
/* Dimensions of the cave*/
  public int  width;
  public int  height;
  
  //Boolean variable that can be toggled in unity
  public bool usesRandSeed;
  
  //Seed to be utilized
  public string seed;
  
  //Range to be used when randomly seeding
  [Range(0,100)]
  
  //Array that will act as our map
  //A one will represent a 'wall'
  int[,] map ;
  
  //Percentage of the cave that is to be filled
  public int randFillPercent;
  
  void Start()
  {
    //Generates the map at the start
    GenerateMap();
  }//end of  start method
  
  void Update()
  {
    if(Input.GetMouseButtonDown(0))
      GenerateMap();
  }//end of update method
  
  void GenerateMap()
  {
    map =  new int[width,height];
    
    //Randomly fills the array with either 0's or 1's
    RandomFillMap();
    
    //Smoothens the map, the index is a prefixed value which we can later change
    for(int i =0 ; i < 5; i++)
    {
      SmoothMap();
    }//end of for loop
    
  }//end of generateMap method
  
  void RandomFillMap(int[,] map)
  {
    //Verifies the 'usesRandSeed' variable
    //In case we need to generate a random seed
    if(usesRandSeed == true)
    {
      //we use the time as our seed
      seed = Time.time.ToString();
    }//end of if
    
    //Creates a Random Number Generator Object and feeds the seed in a hashed form
    System.Random pseudoRand = new System.Random(seed.GetHashCode());
    
    //We loop through our array using the maximum width and height provided
    for(int x = 0 ; x < width; x++)
    {
        for(int y = 0 ; y < height; y++)
        {
          //We verify if the current x or y is in range of the width and height
          if(x == 0 || y == 0 || x == width -1 || y == height -1)
            //if true, then we assign it a 1, symbolizing it's a wall
              map[x,y] = 1;
          else
              //Assigns the current x,y pair an arbitrary 0 or 1
              map[x,y] = (pseudoRand.Next(0,100) < randFillPercent) ? 1:0 ;
          
        }//end of inner for loop 
    }//end of outer for loop
  
  }//end of randFillmethod
  
  void SmoothMap()
  {
    //We loop through the map in x & y
    for (int x = 0; x < width; x++)
    {
      for (int y = 0; y < height; y++)
      {
        //We call a method to calculate nearby 'walls'(aka 1's)
        int neighbouringWallTiles = GetSurroundingWallCount(x,y);
        
        //if the count is greater than the specified number
        //then we turn the current one into a wall as well
        //otherwise, we set it to 0 which means empty space
        if(neighbouringWallTiles > 4)
          map[x,y] = 1;
        else if(neighbouringWallTiles < 4)
          map[x,y] = 0;
        
      }//end of inner for loop
      
    }//end of outer for loop
    
  }//end of SmoothMap method

  int GetSurroundingWallCount(int X, int Y)
  {
      int wallCount = 0;
      
      //We loop through our x and y values
      for(int neighbourX = X -1; neighbourX <= X + 1; neighbourX++)
      {
          for(int neighbourY = Y -1; neighbourY <= Y + 1; neighbourY++)
          {
              //We verify that our current values are within the [0,width) or [0,height) ranges
              if((neighbourX >= 0 && neighbourX < width)&&(neighbourY >= 0 && neighbourY < height))
              {
                  //We make sure not to compare with the tile we provided the method with
                  if(neighbourX != X || neighbourY != Y)
                  
                    //We add the value of the current position in the map array
                    // WARNING! May cause problems if we 
                    //decide to modify our array values at a later point
                    wallCount += map[neighbourX, neighbourY];
                    
              }//end if
              
              else
                  wallCount++;// we increment the wallcount by one
          }//end outer for loop
      }//end outer for loop
      
      //We return the final wallcount
      return wallCount;
  }//end of WallCount method
  
  //A custom made draw method for debugging purposes
  void OnDrawGizmos()
  {
    if(map != null)
    {
      for(int x = 0; x < width ; x++)
      {    for(int y = 0; y < height ; y++)
          {
            //Assigns a color based on the array's value
            // 0 = white : 1 = black
            Gizmos.color = (map[x,y] == 1) ? Color.black:Color.white;
            Vector3 pos =  new Vector3(-width/2 + x + .5f,0,-height/2 + y+ .5f);
            Gizmos.DrawCube(pos,Vector3.one);
            
          }//end inner for loop
          
      }//end outer for loop
      
    }//end if
  
  }//end OnDrawGizmos method
  
}//end of MapGenerator class
