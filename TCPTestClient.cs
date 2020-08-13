using System;
using System.IO;
using System.Net;
using System.Text;
using System.Net.Sockets;
using System.IO.Ports;


public class clnt {

    public static void Main() {
        
        try {
            SerialPort sp = new SerialPort("COM4",9600);
            TcpClient tcpclnt = new TcpClient();
            Console.WriteLine("Enter the IP Address of Device: ");
            Console.WriteLine("\nConnecting.....");
            String ip=Console.ReadLine();
            tcpclnt.Connect(ip,8001);
            // use the ipaddress as in the server program
            sp.Open();
            
            Console.WriteLine("Connected");
            Console.Write("Enter the string to be transmitted : ");
            
            while(true){
                int x=sp.ReadByte();
                int y=x;
                String str=y.ToString();
                Stream stm = tcpclnt.GetStream();
                            
                ASCIIEncoding asen= new ASCIIEncoding();
                byte[] ba=asen.GetBytes(str);
                Console.WriteLine(x);
                
                stm.Write(ba,0,ba.Length);
                
                byte[] bb=new byte[100];
                int k=stm.Read(bb,0,100);
                
                for (int i=0;i<k;i++){
                    Console.Write(Convert.ToChar(bb[i]));  
                }
                if(str=="stop"){
                    tcpclnt.Close();
                }
            }            
        }
        
        catch (Exception e) {
            Console.WriteLine("Error..... " + e.StackTrace);
        }
    }

}