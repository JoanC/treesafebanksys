package object;

import java.io.UnsupportedEncodingException;

public class EncodeTool {
    public static String ISOtoGB2312(String input) throws Exception
    {
    String temp="";
    byte[] bytes = input.getBytes("ISO8859-1");
    temp=new String(bytes,"gb2312");
    return temp;
    }
    

    public static String GB2312toISO(String input) throws Exception
    {
    String temp="";
    try{
       byte[] bytes = input.getBytes("gb2312");
       temp=new String(bytes,"ISO8859-1");
    }catch(Exception ex){
       ex.printStackTrace();
    }
    return temp;
    }
    
    public static String UTF8toISO(String input)
    {
    String temp="";
    try{
       byte[] bytes = input.getBytes("UTF-8");
       temp=new String(bytes,"ISO8859-1");
    }catch(Exception ex){
       ex.printStackTrace();
    }
    return temp;
    }
    
    public static String UTF8toGB2312(String input)
    {
    String temp="";
    try{
       byte[] bytes = input.getBytes("UTF-8");
       temp=new String(bytes,"gb2312");
    }catch(Exception ex){
       ex.printStackTrace();
    }
    return temp;
    }
    
    public static String ByteToISO(String _code){
		byte[] B = null;
		try {
			B = _code.getBytes("iso-8859-1");
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return new String(B);
    }
 
}
