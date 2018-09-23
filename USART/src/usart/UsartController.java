/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package usart;


import gnu.io.CommPortIdentifier;
import gnu.io.PortInUseException;
import gnu.io.SerialPort;
import gnu.io.UnsupportedCommOperationException;
import java.io.IOException;
import java.io.OutputStream;
import static java.lang.Thread.sleep;
import java.util.Enumeration;

public class UsartController {
     static Enumeration portList;
    static CommPortIdentifier portId;
    static SerialPort serialPort;
    static OutputStream outputStream;
    public void sendData(String messageString) throws InterruptedException{
        portList = CommPortIdentifier.getPortIdentifiers();

        while (portList.hasMoreElements()) {

            portId = (CommPortIdentifier) portList.nextElement();
            if (portId.getPortType() == CommPortIdentifier.PORT_SERIAL) {

                if (portId.getName().equals("COM11")) {

                    try {

                        serialPort = (SerialPort) portId.open("UsartController", 2000);

                    } catch (PortInUseException e) {
                        System.out.println("err");
                    }
                    try {
                        outputStream = serialPort.getOutputStream();
                    } catch (IOException e) {
                        System.out.println("err1");
                    }
                    try {
                        serialPort.setSerialPortParams(9600,
                                SerialPort.DATABITS_8,
                                SerialPort.STOPBITS_1,
                                SerialPort.PARITY_NONE);
                    } catch (UnsupportedCommOperationException e) {
                        System.out.println("err2");
                    }
                    try {
                        outputStream.write(messageString.getBytes());
                        sleep(10);
                        outputStream.close();
                        serialPort.close();

                    } catch (IOException e) {
                        System.out.println("err3");
                    }
                }
            }
        }
}}
