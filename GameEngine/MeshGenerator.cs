using Unity;
using System.Collection;
using System;

public class MeshGenerator : MonoBehaviour
{
  public class Node
  {
    public Vector3 pos;
    public int vertIndex = -1;
    
    public Node(Vector3 _pos);
    {
        pos = _pos;
        
    }//end of Node constructor
    
   
  }//end of Node class

   public class ControlNode:Node
  {
    public bool active;
    public Node above, right;
    
    public ControlNode(Vector3 _pos, bool _active,float squareSize )base:( _pos)
    {
        active = _active;
        above = new Node(pos = Vector3.forward *  squareSize/2f);
        right = new Node(pos = Vector3.right * squareSize/2f);
    }//end of ControlNode contructor
    
  }//end of ControlNode class
  
  public class Square
  {
      public ControlNode topLeft,topRight, bottomRight, bottomLeft;
      public Node centerTop, centerRight, centerBottom, centerLeft;
      /*
      public Square(ControlNode tL, ControlNode tR, )
      {
        
      }//end of Square class
      */
  }//end of Square class
  
}//end of MeshGen class
