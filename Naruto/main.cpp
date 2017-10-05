#include<windows.h>
#include "Doremon2.h"
HPEN            g_Pen1= NULL;
LONG WINAPI WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPrevInstance,
LPSTR lpszCmdLine , int nCmdshow)

{
        WNDCLASS wc;
        HWND hwnd;
         HMENU ID_MYTEXT;
        MSG msg;
        /***************** 1.Define Windows class ****************************/
        
	    wc.style =0; // Class style
	    wc.cbWndExtra=100;
		wc.lpfnWndProc = (WNDPROC)WndProc;//window procedure address 
		wc.cbClsExtra = 0; // Class extra bytes
		wc.cbWndExtra =0; // Window extra bytes
		wc.hInstance =hInstance;//Instance handle 
		wc.hIcon = LoadIcon (NULL, IDI_WINLOGO); // Icon handle
		wc.hCursor = LoadCursor (NULL,IDC_ARROW);//Cursor handle
		wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));//Background color
		wc.lpszMenuName= NULL;// Menu name
		wc.lpszClassName="123";//WNDCLASS name
		
	    
		
		
		/***************** 2.Register the Windows class   **********************/

RegisterClass(&wc);
        /***************** 3.Create window      **********************/
hwnd= CreateWindow(
"123",//WNDCLASS name
"doremon",//Window title
 WS_OVERLAPPEDWINDOW,//Window style
 100,//Horizontal position
 100,//Vertical posittion
 1000,//Initial width
 1000,//Initial helight
 HWND_DESKTOP, //Handle of parent window
 NULL,//Menu handle
 
 hInstance,// Application's instance handle
 NULL//Window-creation data
 );
 /***************** 4. Display the window **********************/
 ShowWindow (hwnd,nCmdshow);
 UpdateWindow (hwnd);
 
 /***************** 5. Message loop **********************/
 while (GetMessage (&msg,NULL,0,0)){
 	TranslateMessage (&msg);
 	DispatchMessage(&msg);
 }
 	return msg.wParam;
 }
 
 LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam,
            	LPARAM lParam)
   {
            //	PAINTSTRUCT ps;
//            	HDC hdc;
 
            	switch (message) {
 
            	case WM_PAINT:
            	
                             Doremon2::MyDoremon2::Draw(hwnd);		  
                            	return 0;
                            	
 
            	case WM_DESTROY:
                            	PostQuitMessage (0);
                            	return 0;
            	}
            	return DefWindowProc (hwnd, message, wParam, lParam);
 }
 
 
			

