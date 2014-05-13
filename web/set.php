<?php
file_put_contents("data.txt", "Temp: " . $_GET["temp"] . "
Humidity: " . $_GET["humidity"] . "
Measure time:  " . date("F j, Y, H:i"));

file_put_contents("data.json", "{
\"temp\": " . $_GET["temp"] . ",
\"hum\": " . $_GET["humidity"] . ",
\"time\": \"" . date("F j, Y, H:i") . "\"
}");
