@extends('dashboard.layout.master')

@section('main-content')



<div class="main-content">

  <!-- Header -->
  <div class="header bg-gradient-primary pb-8 pt-5 pt-md-4" style="height=100%">
    <div class="container-fluid">
      <h1 class="text-center text-white">Dispozitive</h1>
       
      <div class="row text-center">

          @foreach ($devices as $device)
          @if(!$device->is_camera) 
          <div class="col-md-6 col-lg-4" style="padding: 10px">
            <!---CARD 2 --->
          <div class="card">
              <div class="card-body">
                  <h4 class="text-center"><i class="fas fa-microchip"></i></h4>
                <h5 class="card-title">RKIT-DEVICE-1</h5>
                <h6 class="card-subtitle mb-2 text-muted">192.168.100.78</h6>
                <p class="card-text text-left">SWITCHES:  <span style="float:right">3</span></p>
                <p class="card-text text-left">PWMs: <span style="float:right">0</span></p>
                <p class="card-text text-left">SENSORS: <span style="float:right">3</span></p>
                <p></p>
                <h5>Status: <i class="fas fa-circle" style="color:green"></i> ONLINE</h6>
                <a type="button" class="btn btn-danger" style="color:crimson"><i class="fas fa-window-close text-center"></i></a>
              </div>
            </div>
          <!---ENDCARD --->
          </div>
          @endif
          @if($device->is_camera) 
          <div class="col-md-6 col-lg-4" style="padding: 10px">
              <!---CARD 3 --->
              <div class="card" style="height:100%;">
                  <div class="card-body">
                    <h4 class="text-center"><i class="fas fa-video-camera"></i></h4>
                    <h5 class="card-title">RKIT-CAMERA-1</h5>
                  <h6 class="card-subtitle mb-2 text-muted">{{$device->connection_adress}}</h6>
                    <br>
                  <a href="http://{{$device-connection_adress}}/html" class="fa fa-external-link" style="font-size: 50px"></a>
                    <div style="height:54px"></div>
                  <h5>Status: <i class="fas fa-circle" style="color:{{ ($device->getOnline($device->connection_adress) ? 'green' : 'red') }}"></i> {{ ($device->getOnline($device->connection_adress) ? 'ONLINE' : 'OFFLINE') }}</h6>
                    <a type="button" class="btn btn-danger" style="color:crimson"><i class="fas fa-window-close text-center"></i></a>
                  </div>
                </div>
              <!---ENDCARD --->
            </div>
          @endif
          @endforeach
        
          <div class="col-md-6 col-lg-4" style="padding: 10px">
              <!---CARD NEW --->
              <div class="card" style="">
                  <div class="card-body" style="">
                    <a class="btn btn-info" type="button" href=""><h1 class="text-center"><i class="fas fa-plus-circle"></i></h4>
                      <h5 class="card-title">Adauga dispozitiv</h5></a>
                  </div>
                </div>
              <!---ENDCARD --->
            </div>
      </div>

    </div>
  </div>
  <!---END HEADER--->
</div>

@endsection