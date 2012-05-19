(*
  
  input:	|  output:	
		|
 name	| $name=$_GET['$name'];
 email	| $email=$_GET['$email'];
 city  	| $city=$_GET['$city'];
 phone	| $phone=$_GET['$phone'];
 
*)
on CodaScriptSettings()
	return {displayName:"GET/POST/SESSION Variables", inContextMenu:"yes"}
end CodaScriptSettings

set generateOutput to ""

tell application "Coda"
	try
		tell current split of front document
			if selected text is equal to "" then
				display alert "No text selected"
				return
			else
				set someText to selected text
				set kindOfVar to button returned of (display dialog "Type of variable?" buttons {"GET", "POST", "SESSION"})
				repeat with i from 1 to count of every paragraph in someText
					if paragraph i in someText is not "" then
						set var to paragraph i in someText
						if first character of var is not "$" then
							set var to "$" & var
						end if
						set generateOutput to generateOutput & var & "=$_" & kindOfVar & "['" & var & "'];
"
					end if
				end repeat
				set selected text to generateOutput
			end if
		end tell
	on error
		beep
		return
	end try
end tell