@extends('dashboard.layout.master')

@section('main-content')

<div class="main-content">

  <!-- Header -->
  <div class="header bg-gradient-primary pb-8 pt-5 pt-md-4" style="height=100%">
    <div class="container-fluid">
      <h1 class="text-center text-white">Dashboard</h1>
      <div class="tabs">
        <div class="nav-wrapper">
          <ul class="nav nav-pills nav-fill flex-column flex-md-row" id="tabs-icons-text" role="tablist">
              <li class="nav-item">
                  <a class="nav-link mb-sm-3 mb-md-0 active" id="tabs-icons-text-1-tab" data-toggle="tab" href="#tabs-icons-text-1" role="tab" aria-controls="tabs-icons-text-1" aria-selected="true"><i class="ni ni-cloud-upload-96 mr-2"></i>General Info</a>
              </li>
              <li class="nav-item">
                  <a class="nav-link mb-sm-3 mb-md-0" id="tabs-icons-text-2-tab" data-toggle="tab" href="#tabs-icons-text-2" role="tab" aria-controls="tabs-icons-text-2" aria-selected="false"><i class="ni ni-ui-04 mr-2"></i>Switches</a>
              </li>
              <li class="nav-item">
                  <a class="nav-link mb-sm-3 mb-md-0" id="tabs-icons-text-3-tab" data-toggle="tab" href="#tabs-icons-text-3" role="tab" aria-controls="tabs-icons-text-3" aria-selected="false"><i class="ni ni-sound-wave mr-2"></i>Sensors</a>
              </li>
          </ul>
      </div>
      <div class="card shadow">
          <div class="card-body">
              <div class="tab-content" id="myTabContent">
                  <!---General Info --->
                  <div class="tab-pane fade show active" id="tabs-icons-text-1" role="tabpanel" aria-labelledby="tabs-icons-text-1-tab">

                  </div>
                  <!---Switches --->
                  <div class="tab-pane fade" id="tabs-icons-text-2" role="tabpanel" aria-labelledby="tabs-icons-text-2-tab">

                  </div>
                  <!---Sensors --->
                  <div class="tab-pane fade" id="tabs-icons-text-3" role="tabpanel" aria-labelledby="tabs-icons-text-3-tab">

                  </div>
              </div>
          </div>
      </div>
      </div>
    </div>
  </div>
  <!---END HEADER--->

  <iframe src="http://192.168.100.232/html/" height="500px" width="100%">
    <p>Your browser does not support iframes.</p>
  </iframe>
</div>

@endsection