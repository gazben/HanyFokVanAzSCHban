/**
 * Created by Gujci on 11/05/14.
 */
(function update() {
    $.ajax({
        url: "data.json",
        context: document.body
    }).done(function (mydata) {
            document.getElementById("humidity").ariaValuenow = mydata.hum;
            document.getElementById("humidity").style.width = min(mydata.hum, 100) + "%";
            document.getElementById("humidity").innerHTML = "Páratartalom: " + mydata.hum + "%";

            document.getElementById("temp").ariaValuenow = mydata.temp;
            document.getElementById("temp").style.width = min(mydata.temp * 2, 100) + "%";
            document.getElementById("temp").innerHTML = "Hőmérséklet: " + mydata.temp + " °C";

            document.getElementById("time").innerHTML = mydata.time;
        });
    setTimeout(update, 1000);
})();

var min = function (a, b) {
    return a < b ? a : b;
}