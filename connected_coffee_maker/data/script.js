function onButton() {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "on", true);
  xhttp.send();
}

function offButton() {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "off", true);
  xhttp.send();
}

function smallButton() {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "small", true);
  xhttp.send();
}

function bigButton() {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "big", true);
  xhttp.send();
}

setInterval(function getData() {
  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("waterLevel").innerHTML = this.responseText;
    }
  };

  xhttp.open("GET", "readWaterLevel", true);
  xhttp.send();
}, 2000);

function with_text() {
  var span = document.getElementById("span_txt");
  if (span.innerHTML == "") {
    span.innerHTML = "Please wait a minute ...";
  } else {
    span.innerHTML = "Please wait a minute ...";
  }
}

function without_text() {
  var span = document.getElementById("span_txt");
  if (span.innerHTML != "") {
    span.innerHTML = "";
  } else {
    span.innerHTML = "";
  }
}

