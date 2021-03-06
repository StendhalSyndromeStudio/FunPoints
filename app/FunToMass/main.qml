import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQml.Models 2.1
import QtQuick.Controls.Material 2.3
import com.fun.fpcore 1.0
import "ComponentFactory.js" as Factory
import QtPositioning 5.5
import com.fun.fpcore 1.0
import QtWebView 1.1

ApplicationWindow {
    id: app
    visible: true
    width: 640
    height: 480
    title: qsTr("Развлечения в массы")

    property variant newPoiCoord: QtPositioning.coordinate( 0, 0 )

    Item {
        anchors.fill: parent
        MapLeningrad {
            id: map
        }
        // создание новой poi
        EventParams {
            id: eventParams
            visible: false
        }

        Connections {
            target: map
            onInvokeEventParams: {
                controlsButton.visible = false
                eventParams.visible = true
                app.newPoiCoord = QtPositioning.coordinate( x, y )


                //console.log( 'xy', x, y )
            }
        }

        Connections {
            target: eventParams
            onCreateNewPoi: {
                controlsButton.visible = true
                //console.log( type, hour, title )

                if ( FpCore.user( ).canCreateEvent( ) ) {
                        var stor    = FpCore.user().createdEvents( );
                        var event   = stor.create( title, type, newPoiCoord.latitude, newPoiCoord.longitude, FpCore.user() );
                }

                //map.createNewPoi( newPoiCoord.latitude, newPoiCoord.longitude, type, hour, title )
            }
        }
        /////////////////////////////////
        FilterringPage {
            id:filterringPage
            visible: false
            onAccept: {
                controlsButton.visible = true
            }
        }
        // QrCodeTest
        QrCodeTest {
            id:qrCodeId

            visible: false
            onExit: {
                controlsButton.visible = true
            }
        }

        /////////////
        ControlButtons {
            id:controlsButton
            width: 70
            height: 300//contentItem.height
            anchors.right: map.right
            anchors.bottom: map.bottom
            anchors.bottomMargin: 20
            anchors.rightMargin: 20
            onListEventsClicked : {
                eventsList.state = "half";
            }
            onPayClick : {
                console.log( 'pay instance' )
                controlsButton.visible = false
                qrCodeId.visible = true
            }

            onFilterClicked : {
                console.log( 'filter instance' )
                controlsButton.visible = false
                filterringPage.visible = true
            }
            onLocationClicked: {
                map.propCenter = map.locationLeningrad;
            }
        }
        Item {
            id: eventsList
            //anchors.fill: parent
            width: parent.width
            height: 300
            //color: "#2d2d2d"
            anchors.bottom: map.bottom
            //color: "#2d2d2d"


            /*
        for(var i = 0; i < FpCore.eventCount(); ++i) {
            var event = FpCore.eventAt( i );
            var coordinate = event.location( );
            //var timeSpan = event.timeSpending( ).span;
            var title = event.name( );
            console.log( "add point", title );
            markerModel.addMarker( coordinate, title  )
            //markerModel.title( title );
            //markerModel.selectPoint( coordinate )

            mapview.update( )
        }

*/


            /*
virtual QString name() const;
virtual QStringList tags() const;
virtual QString description() const;
virtual Status status() const;
virtual IUser *organizer() const;
    virtual QString firstName() const = 0;
    virtual QString lastName() const = 0;
    virtual QString patronimic() const = 0;
    virtual QString shortName() const = 0;

IRateObject *rate()
    virtual double rate() const;
    virtual QList<IFeedback *> feedback() const;

virtual QDateTime start() const;
virtual QDateTime end() const;
virtual QGeoCoordinate location() const;
    Q_PROPERTY(double latitude READ latitude WRITE setLatitude)
    Q_PROPERTY(double longitude READ longitude WRITE setLongitude)
    Q_PROPERTY(double altitude READ altitude WRITE setAltitude)
    Q_PROPERTY(bool isValid READ isValid)
*/


            ListModel {
                signal askRoute(double latitude, double longitude)
                signal askDetails(double latitude, double longitude, int index)

                onAskRoute: {
                    map.propMarkerModel.selectPoint(QtPositioning.coordinate( latitude, longitude ));
                }

                onAskDetails: {
                    eventsList.state = "details";
                    console.log("details");
                    details.coordinate =QtPositioning.coordinate( latitude, longitude );
                    var item = eventsModel.get(index);
                    details.name = item.name;
                    console.log(details.name);
                    details.address = item.address;
                    details.description = item.description;
                    details.organizerString = item.organizerString;
                    details.rateImgUrl = item.rateImgUrl;
                    details.startFormatted = item.startFormatted;
                    details.endFormatted = item.endFormatted;



                    /*
            property string name: ""
            property variant coordinate: QtPositioning.coordinate( 0, 0 )
            property string address: ""
            property string description: ""
            property string organizerString: ""
            //property double rate: ""
            //property string rateString: ""
            property string rateImgUrl: ""
            property string startFormatted: ""
            property string endFormatted: ""
*/
                }

                function organizerToString(value){
                    var result = "";
                    if(!value) return result;
                    result += value.lastName();
                    result += " " + value.firstName();
                    result += " " + value.patronimic();
                    return result;
                }

                function coordinateToStringAddress(value){
                    var result = "";
                    //TODO: конвертировать в адрес через сервис
                    return result;
                }

                function rateToString(value){
                    value = +value;
                    if((value !== value) || (!value) || (value < 0)) return "";
                    var result = "";
                    for(var i = 0; i < value && i < 5; ++i){
                        result += "*";
                    }
                    return result;
                }

                function rateToImageUrl(value){
                    value = +value;
                    if((value !== value) || (!value) || (value < 0)) return "";
                    if(value >= 1 && value < 2) return "star1.png";
                    if(value >= 2 && value < 3) return "star2.png";
                    if(value >= 3 && value < 4) return "star3.png";
                    if(value >= 4 && value < 5) return "star4.png";
                    if(value >= 5) return "star5.png";
                    return "";
                }

                function formatDate(date) {
                  var monthNames = [
                    "Января", "Февраля", "Марта",
                    "Апреля", "Мая", "Июня", "Июля",
                    "Августа", "Сентября", "Октября",
                    "Ноября", "Декабря"
                  ];

                  var day = date.getDate();
                  var monthIndex = date.getMonth();
                  var year = date.getFullYear();

                  return day + ' ' + monthNames[monthIndex] + ' ' + year;
                }

                id: eventsModel
                Component.onCompleted: {
                    //var flag = false;
                    function update () {
                        //if(flag) return;
                        //flag = true;
                        eventsModel.clear();
                        for(var idx = 0; idx < FpCore.eventCount(); ++idx){
                            var event = FpCore.eventAt( idx );
                            var listElem = {};
                            listElem.name = event.name( );
                            listElem.coordinate = event.location( );
                            listElem.address = coordinateToStringAddress(listElem.coordinate);
                            listElem.description = event.description( );
                            listElem.organizer = event.organizer( );
                            listElem.organizerString = organizerToString(listElem.organizer);
                            listElem.rate = (event.rate( ) || {rate : function(){}}).rate( ) || 0; //да, именно 2 раза
                            listElem.rateString = rateToString(listElem.rate);
                            listElem.rateImgUrl = rateToImageUrl(listElem.rate);
                            listElem.start = event.start( );
                            listElem.end = event.end( );
                            listElem.startFormatted = formatDate( listElem.start );
                            listElem.endFormatted = formatDate( listElem.end );
                            console.log(listElem);

                            eventsModel.insert(idx,listElem);

                        }
                        //flag = false;
                    }

                    update();
                    FpCore.onEventListChanged.connect(update);
                }
            }

            ScrollView {
                id: eventsContainer
                anchors.left: parent.left
                anchors.right: parent.right
                //anchors.bottom: map.bottom
                height: eventsList.height - minMaxButtons.height


                ListView {
                  //anchors.fill: parent
                  model: eventsModel
                  id: lv
                  spacing: 10
                  width: parent.width

                  /*
                        listElem.name = event.name( );
                        listElem.coordinate = event.location( );
                        listElem.address = coordinateToStringAddress(listElem.coordinate);
                        listElem.description = event.description( );
                        listElem.organizer = event.organizer( );
                        listElem.organizerString = organizerToString(listElem.organizer);
                        listElem.rate = event.rate( ).rate( ); //да, именно 2 раза
                        listElem.start = event.start( );
                        listElem.end = event.end( );

*/

                  delegate:
                    Rectangle {
                        width: parent.width
                        height: childrenRect.height

                        color: index % 2 == 0 ? "#ccb0a0" : "#cfbfaf"//"#aa3040"
                        radius: 10
                        Row {
                            spacing: 3
                            Image {
                                //anchors.fill: parent
                                source: "imgs/key.png"
                            }
                            Column {
                                spacing: 3
                                Text { text : name; font.pointSize: 20 }
                                Text { text : startFormatted + " - " + endFormatted; font.pointSize: 16 }
                                Text { text : address; font.pointSize: 18 }
                                Row {
                                    Image { source : "imgs/"+rateImgUrl }
                                    Text { text : organizerString; font.pointSize: 20 }
                                }
                                //Text { text : "Организатор *****" }
                            }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                eventsModel.askRoute(coordinate.latitude,coordinate.longitude);
                                console.log(coordinate.latitude + " " + coordinate.longitude);
                            }
                            onPressAndHold: {
                                eventsModel.askDetails(coordinate.latitude,coordinate.longitude, index);
                            }
                        }
                    }
                }
            }
            MinMaxButtons {
                id: minMaxButtons
                width: 40
                height: 50
                anchors.bottom: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
//                maximizeClick: console.log("111111111111");
//                minimizeClick: console.log("111111111111");
                onMaximizeClicked: {
                    if(eventsList.state === "half"){
                        eventsList.state = "maximized";
                    } else if(eventsList.state === "minimized") {
                        eventsList.state = "half";
                    }
                }
                onMinimizeClicked: {
                    if(eventsList.state === "half"){
                        eventsList.state = "minimized";
                    } else if(eventsList.state === "maximized") {
                        eventsList.state = "half";
                    }
                }

            }





            states: [
                State {
                    name: "minimized"
                    PropertyChanges { target: eventsList; height: 100; visible: false }
                    PropertyChanges { target: details; visible: false }
                },
                State {
                    name: "maximized"
                    PropertyChanges { target: eventsList; height: eventsList.parent.height }
                    PropertyChanges { target: details; visible: false }
                },
                State {
                    name: "half"
                    PropertyChanges { target: eventsList; height: eventsList.parent.height / 2 }
                    PropertyChanges { target: details; visible: false }
                },
                State {
                    name: "details"
                    PropertyChanges { target: details; visible: true }
                    PropertyChanges { target: eventsList; height: 100; visible: false }

                }
            ]
            state: "minimized"
        }
        Rectangle {
            id: details
            anchors.fill: parent

            property string name: ""
            property variant coordinate: QtPositioning.coordinate( 0, 0 )
            property string address: ""
            property string description: ""
            property string organizerString: ""
            //property double rate: ""
            //property string rateString: ""
            property string rateImgUrl: ""
            property string startFormatted: ""
            property string endFormatted: ""



            /*
                    listElem.name = event.name( );
                    listElem.coordinate = event.location( );
                    listElem.address = coordinateToStringAddress(listElem.coordinate);
                    listElem.description = event.description( );
                    listElem.organizer = event.organizer( );
                    listElem.organizerString = organizerToString(listElem.organizer);
                    listElem.rate = (event.rate( ) || {}).rate( ) || 0; //да, именно 2 раза
                    listElem.rateString = rateToString(listElem.rate);
                    listElem.rateImgUrl = rateToImageUrl(listElem.rate);
                    listElem.start = event.start( );
                    listElem.end = event.end( );
                    listElem.startFormatted = formatDate( listElem.start );
                    listElem.endFormatted = formatDate( listElem.end );

*/

            Rectangle {
                id: detailsHead
                width: parent.width
                height: 70
                color: "#ccb0a0"//"#dd3030"
                radius: 10
                Row {
                    spacing: 3
                    Image {
                        source: "imgs/key.png"
                    }
                    Column {
                        spacing: 3
                        Text { text : details.name; font.pointSize: 20 }
                        Text { text : details.startFormatted + " - " + details.endFormatted; font.pointSize: 16 }
                        Text { text : details.address; font.pointSize: 18 }
                        Row {
                            Image { source : "imgs/"+details.rateImgUrl }
                            Text { text : details.organizerString; font.pointSize: 20 }
                        }
                        //Text { text : "Организатор *****" }
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        eventsList.state = "minimized";
                        //eventsModel.askRoute(coordinate.latitude,coordinate.longitude);
                        console.log(details.coordinate.latitude + " " + details.coordinate.longitude);
                    }
                    onPressAndHold: {
                        //eventsModel.askDetails(coordinate.latitude,coordinate.longitude);
                    }
                }
            }
            Rectangle {
                id: detailsBody
                width: parent.width
                anchors.top: detailsHead.bottom
                anchors.bottom: parent.bottom
                Text { id: descr; text : details.description; font.pointSize: 14 }
                WebView {
                        id: webView
                        width: detailsBody.width
                        anchors.top: descr.bottom
                        anchors.bottom: detailsBody.bottom

                        //url: 'https://www.youtube.com/'
                        Component.onCompleted: {
                            //webView.url = 'qrc:/index.html';
                                var resource = 'qrc:/index.html';

                                var xhr = new XMLHttpRequest;
                                xhr.open('GET', resource);
                                xhr.onreadystatechange = function() {
                                    if (xhr.readyState === XMLHttpRequest.DONE) {
                                        var response = xhr.responseText;
                                        webView.loadHtml(response);
                                    }
                                };
                                xhr.send();
                        }
                    }
            }
        }
    }
}
