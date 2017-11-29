Jonathan An

To run the program: render “samplemesh”.txt

-------Keyboard Functions----------
't' = translate
'r' = rotate
'w' = translate up along y-axis/rotate up about x-axis
's' = translate down along y-axis/rotate down about x-axis
'a' = translate left along x-axis/rotate left about y-axis
'd' = translate right along x-axis/rotate right about y-axis
'i' = render image (May take some time)
'l' = subdivide
'g' = toggle view (FRONT/TOP/SIDE)
'esc' = exit

----------Notes---------
-You may press 'r' or 't' to go back to wireframe mode after rendering the image.
-The shadow created after rendering the image sometimes overlaps part of the mesh.
 (you can comment out the shadowRender function in the rayRender() function 
 under //FRONT VIEW
-I have attempted to implement anti-aliasing by 2x2 supersampling.
