using System;
using System.Text;
using System.Net;
using System.Net.Sockets;

public class serv {
    public static void Main() {
    try {
        IPAddress ipAd = IPAddress.Parse("127.0.0.1");

        TcpListener myList=new TcpListener(ipAd,8001);
     
        myList.Start();
        
        Console.WriteLine("The server is running at port 8001...");    
        Console.WriteLine("The local End point is  :" + 
                          myList.LocalEndpoint );
        Console.WriteLine("Waiting for a connection.....");
        
        Socket s=myList.AcceptSocket();
        Console.WriteLine("Connection accepted from " + s.RemoteEndPoint);
        while(true){
            byte[] b=new byte[100];
            int k=s.Receive(b);
            for (int i=0;i<k;i++){
                char x=Convert.ToChar(b[i]);
                Console.Write(x);
            }

            ASCIIEncoding asen=new ASCIIEncoding();
            s.Send(asen.GetBytes("The string was recieved by the server."));
            
        }


            
    }
    catch (Exception e) {
        Console.WriteLine("Error..... " + e.StackTrace);
    }    
    }
    
}