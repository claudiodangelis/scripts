


(*
$dbh = mysqli_connect($hostname,$username,$password,$dbname) or 
  die("Problem connecting: ".mysqli_error());
//run a query, returning a result set
$result = mysqli_query($dbh,"SELECT field1,field2 FROM tablename");
// loop through the result set and display the results
while ($row = mysqli_fetch_assoc($result)){
  echo $row['field1'].$row['field2]."\n";

//free the memory and close the connection
mysqli_free_result($result);
mysqli_close($dbh);
*)

on CodaScriptSettings()
	return {displayName:"GET/POST/SESSION Variables", inContextMenu:"yes"}
end CodaScriptSettings

set generateOutput to ""

tell application "Coda"
	try
		tell current split of front document
			set mysql_hostname to text returned of (display dialog "Input mysql host
(both text or $variable)" default answer "$mysql_hostname")
			set mysql_username to text returned of (display dialog "Input mysql username
(both text or $variable)" default answer "$mysql_username")
			set mysql_password to text returned of (display dialog "Input mysql password
(both text or $variable)" default answer "$mysql_password")
			set mysql_query to text returned of (display dialog "Input mysql query
(both text or $variable)" default answer "$mysql_query")
			set mysql_dbname to text returned of (display dialog "Input mysql database name
(both text or $variable)" default answer "$mysql_dbname")
			
			set selected text to "$dbh = mysqli_connect(\"" & mysql_hostname & "\",\"" & mysql_username & "\",\"" & mysql_password & "\",\"" & mysql_dbname & "\") or die(\"Problem connecting: \".mysqli_error());
$result = mysqli_query($dbh,\"" & mysql_query & "\");
while ($row = mysqli_fetch_assoc($result)){
 
 // line by line executing code here

}

mysqli_free_result($result);
mysqli_close($dbh);"
			
		end tell
	on error
		beep
		return
	end try
end tell
