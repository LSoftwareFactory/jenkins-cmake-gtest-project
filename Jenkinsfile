pipeline{
    agent any
    
    environment {
        LOG_JUNIT_RESULTS = 'true'
    }
 
    /*-------- CODE CLONE ------------ */
    stages{
        stage('git pull'){
            steps{
             sh 'rm -rf $WORKSPACE/*'
            checkout ([$class: 'GitSCM', branches: [[name: '*/master']],
                       userRemoteConfigs: [[url: 'https://github.com/LSoftwareFactory/jenkins-cmake-gtest-project']],
                ])
            }
        }
        /*--------------------------- Build Stage ----------------------- */
        stage('Build'){
            steps{
                echo "Build number is ${currentBuild.number}"
                sh '''
                  cd $WORKSPACE
                  sh build.sh
                  '''
             }
        }
        /*    ----------------- Unit Test Stage ------------------- */
        stage('Unit Test'){
            steps{
                 sh """
                    cd $WORKSPACE/test
                    mkdir build
                    cd build
                    cmake .. -DCMAKE_PREFIX_PATH=../install
                    make
                    ./app-sample-addition-test --gtest_output="xml:TestReport-Build${currentBuild.number}.xml"

                 """
                
              }
       }
        /*    ----------------- Coverage Test Stage ------------------- */
        stage('Coverage Test'){
            steps{
                  sh '''
                    cd $WORKSPACE/test
                 '''
                

              }
       }
  

     }
     post {
        always {
            junit checksName: 'Tests', testResults: 'test/build/*.xml'
            influxDbPublisher(selectedTarget: 'junit-test-data')

            archiveArtifacts artifacts: 'test/build/app-sample-addition-test', fingerprint: true
        
        }

    }
  }
