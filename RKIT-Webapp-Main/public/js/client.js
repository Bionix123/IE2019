var socket = io("http://"+webSocketAdress+":"+webSocketPort);

var checkboxes = [false,false,false];

socket.on('checkboxes states', (data)=>{
  console.log(data);
  checkboxes = data.status;
  updateCheckboxes(checkboxes);
});

$('#myonoffswitch1').click(function() {
    if ($(this).is(':checked')) {
        $.get("http://"+slaveIpAdress+"/relay/turnon?relay_id=1");
        checkboxes[0] = true;
        socket.emit('checkbox change', checkboxes);
    } else {
        $.get("http://"+slaveIpAdress+"/relay/turnoff?relay_id=1");
        checkboxes[0] = false;
        socket.emit('checkbox change', checkboxes);
    }
});

$('#myonoffswitch2').click(function() {
    if ($(this).is(':checked')) {
        $.get("http://"+slaveIpAdress+"/relay/turnon?relay_id=2");
        checkboxes[1] = true;
        socket.emit('checkbox change', checkboxes);
    } else {
        $.get("http://"+slaveIpAdress+"/relay/turnoff?relay_id=2");
        checkboxes[1] = false;
        socket.emit('checkbox change', checkboxes);
    }
});

$('#myonoffswitch3').click(function() {
    if ($(this).is(':checked')) {
        $.get("http://"+slaveIpAdress+"/relay/turnon?relay_id=3");
        checkboxes[2] = true;
        socket.emit('checkbox change', checkboxes);
    } else {
        $.get("http://"+slaveIpAdress+"/relay/turnoff?relay_id=3");
        checkboxes[2] = false;
        socket.emit('checkbox change', checkboxes);
    }
});

function updateCheckboxes(data){
  $('#myonoffswitch1').prop('checked', data[0])
  $('#myonoffswitch2').prop('checked', data[1])
  $('#myonoffswitch3').prop('checked', data[2])
}