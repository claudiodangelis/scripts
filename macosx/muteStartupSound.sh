# Mute the Mac OS X startup sound: the fastest way.
# Copy/paste lines below and put in your password when prompted.
#
# If you want to restore startup sound, type:
#   
#   sudo defaults delete com.apple.loginwindow LoginHook
#   sudo defaults delete com.apple.loginwindow LogoutHook
#   sudo rm /usr/local/bin/mute /usr/local/bin/unmute

sudo sh -c "echo '#'"'!'"'/bin/sh\nosascript -e \"set volume without output muted\"'>/usr/local/bin/unmute"
sudo sh -c "echo '#'"'!'"'/bin/sh\nosascript -e \"set volume with output muted\"'>/usr/local/bin/mute"
sudo chmod a+x /usr/local/bin/mute /usr/local/bin/unmute
sudo defaults write com.apple.loginwindow LoginHook /usr/local/bin/unmute
sudo defaults write com.apple.loginwindow LogoutHook /usr/local/bin/mute