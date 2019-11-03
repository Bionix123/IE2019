@include('dashboard.layout.credits')
<!DOCTYPE html>
<html lang="en">

<head>
  @include('dashboard.layout.head') <!--head stuff-->
</head>

<body class="">
  <!---NAVBAR--->
  @include('dashboard.layout.navbar')
  <!---END NAVBAR--->

  <!---Main Content--->
  @yield('main-content')
  <!---END Main Content--->

  <!--footer scripts-->
  @include('dashboard.layout.footer-scripts')
</body>
