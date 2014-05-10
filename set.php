<?php

file_put_contents("data.txt","Temp: ".$_GET["temp"]."
 Humidity: ".$_GET["humidity"]."
 Measure time:  ".date("F j, Y, g:i a"));
file_put_contents("index.html",

"<html>
<head>
<meta charset= "UTF8"/>
<title>Hány fok van az 710-ben?</title>
<link href="//netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<h1>Ennyi fok uralkodik jelenleg az SCH710-es szobájában</h1>
<br />
Temp: ".$_GET["temp"]."
<br />
Humidity: ".$_GET["humidity"]."
<br />
Measure time:  ".date("F j, Y, g:i a")."
<br >
<br />
<br >
Opre feladat is live! made by Balu&&Gazben
<br />

<script src="//netdna.bootstrapcdn.com/bootstrap/3.1.1/js/bootstrap.min.js"></script>
</body>
</html>");

?>