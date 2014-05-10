<?php
file_put_contents("data.txt","Temp: ".$_GET["temp"]."
 Humidity: ".$_GET["humidity"]."
 Measure time:  ".date("F j, Y, g:i a"));
 
file_put_contents("datas.php", "Temp: ".$_GET["temp"]." C
<br />
Humidity: ".$_GET["humidity"]."%
<br />
Measure time:  ".date("F j, Y, g:i a")."
<br >
<br />");
?>