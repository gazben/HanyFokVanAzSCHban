<html>
<head>
    <title>Hány fok van az 710-ben?</title>
    <meta charset= "UTF8"/>
    <link href="//netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<div class="jumbotron">
    <h1>Ennyi fok uralkodik jelenleg az SCH710-es szobájában</h1>


<div id="php">
    <?php

            <div class="progress">
              <div class="progress-bar progress-bar-warning" role="progressbar" aria-valuenow="\".$_GET["temp"].\"" aria-valuemin="0" aria-valuemax="100" style="width: \".$_GET["temp"].\"">
                Temp: ".$_GET["temp"]."
              </div>
            </div>


            <div class="progress">
              <div class="progress-bar" role="progressbar" aria-valuenow="\".$_GET["humidity"].\"" aria-valuemin="0" aria-valuemax="100" style="width: \".$_GET["humidity"].\";">
                Humidity: ".$_GET["humidity"]."
              </div>
            </div>

            <p> Measure time: ".date("F j, Y, g:i a")." </p>

    ?>
</div>
</div>

<div class="panel panel-default" style="text-align: center; bottom: 20px; position: absolute;">
  <div class="panel-body">
    Opre feladat is live! made by Balu&&Gazben
    <br />
            On Bootsrtap
  </div>
</div>


</body>

</html>