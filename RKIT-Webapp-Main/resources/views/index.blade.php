<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title>Control My Stuff | DailyIoT</title>

    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="//netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap.min.css">

    <!-- Optional theme -->
    <link rel="stylesheet" href="//netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap-theme.min.css">

    <!-- Custom styles for this template -->
    <link href="/css/style.css" rel="stylesheet">

<script src="http://{{$webSocketAdress}}:{{$webSocketPort}}/socket.io/socket.io.js"></script>

</head>
<body>

    <div class="site-wrapper">
        <div class="site-wrapper-inner">
            <div class="cover-container">

                <div class="inner cover">
                    <h1 class="cover-heading">Control My Stuff</h1>
                    <div class="onoffswitch" style="margin:0px auto;">
                        <div class="switch demo3">
                            <input type="checkbox" id="myonoffswitch1">
                            <label><i></i></label>
                        </div>
                    </div>
                </div>

                <div class="inner cover">
                    <h1 class="cover-heading">Control My Stuff</h1>
                    <div class="onoffswitch" style="margin:0px auto;">
                        <div class="switch demo3">
                            <input type="checkbox" id="myonoffswitch2">
                            <label><i></i></label>
                        </div>
                    </div>
                </div>

                <div class="inner cover">
                    <h1 class="cover-heading">Control My Stuff</h1>
                    <div class="onoffswitch" style="margin:0px auto;">
                        <div class="switch demo3">
                            <input type="checkbox" id="myonoffswitch3">
                            <label><i></i></label>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <script src="//code.jquery.com/jquery-1.11.0.min.js"></script>
    <script src="//code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
    <script> 
    var slaveIpAdress = "{{$slaveIpAdress}}"; 
    var webSocketAdress = "{{$webSocketAdress}}";
    var webSocketPort = "{{$webSocketPort}}";
    </script>
    <script src="/js/client.js"></script>
</body>

</html>