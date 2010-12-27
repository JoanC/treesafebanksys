package object;

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
       byte[] bytes = input.getBytes("utf-8");
       temp=new String(bytes,"ISO8859-1");
    }catch(Exception ex){
       ex.printStackTrace();
    }
    return temp;
    }
}
