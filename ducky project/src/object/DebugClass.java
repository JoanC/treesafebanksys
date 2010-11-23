package object;
import java.util.Calendar;
import java.text.SimpleDateFormat;
import javax.swing.filechooser.FileSystemView;

import sun.misc.OSEnvironment;

import java.io.*;



public class DebugClass {
	
	static public void debug_info(String _modle_name,String _info){
		Calendar rightNow = Calendar.getInstance();
        SimpleDateFormat fmt_detail = new SimpleDateFormat("yyyy/MM/dd   hh:mm:ss   ");
         String sysDatetime = fmt_detail.format(rightNow.getTime());
         File _logFile =createLogFile(rightNow);
         
		writeLogInfo( (sysDatetime + "modle " + _modle_name + ": " + _info) , _logFile);
	}
		private static File createLogFile(Calendar _date){
			FileSystemView fsv = FileSystemView.getFileSystemView();
			 SimpleDateFormat fmt_simple = new SimpleDateFormat("yyyy_MM_dd");
			 String sysFileNameData = fmt_simple.format(_date.getTime());
			String _file_path = fsv.getHomeDirectory() + "\\" + "_java_log" + "_" + sysFileNameData + "_" + ".txt";
			File _log_file = new File(_file_path);//取得一个file对象
			 if(!_log_file.exists()){
			        try{
			        	_log_file.createNewFile();
			        }
			        catch (IOException e) {
						// TODO: handle exception
			        	System.out.println("create error! The path is " + _file_path);
					}
		        }
			 return _log_file;
		}
			private static void writeLogInfo(String _info,File _file){
				FileOutputStream os = null;
				try {
				    os =new FileOutputStream(_file,true);
				   } catch (FileNotFoundException e) {
				    // TODO Auto-generated catch block
				    e.printStackTrace();
				   }
				 byte[] _buff = (_info + "\r\n").getBytes();
				//写文件
				 try {
					os.write(_buff);
					os.close();
				} catch (IOException e) {
					// TODO Auto-generated catch bloc
					e.printStackTrace();
				}
			}
		}
