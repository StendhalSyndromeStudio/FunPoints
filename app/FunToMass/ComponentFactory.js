//.pragma library

console.log("Factory load");
var create = function(){
    console.log("Factory start");
    var undefined;
    var components = {};
    return (function(url, parent, properties, postprocessing){
        console.log("Factory.create",url,parent,properties);
        var component;
        var object;

        var finishCreation = function( ) {
            if (component.status === Component.Ready) {
                components[url] = components[url] || component;
                object = component.createObject(parent || null, properties || {});
                if (object === null) {
                    // Error Handling
                    console.log("Error creating object");
                } else {
                    console.log("postprocessing",postprocessing);
                    if( (typeof postprocessing) === "function" ){
                        postprocessing(object);
                    }
                }
            } else if (component.status === Component.Error) {
                // Error Handling
                console.log("Error loading component:", component.errorString());
            }
        }

        var createObject = function( ) {
            console.log("Factory createObject");
            component = components[url] || Qt.createComponent(url);
            console.log("Factory createObject", component, component.status, Component.Ready);
            if (component.status === Component.Ready){
                console.log("Factory createObject ready");
                finishCreation();
            }
            else {
                console.log("Factory createObject connect");
                component.statusChanged.connect(finishCreation);
            }
        }
        createObject();
    });
}();
