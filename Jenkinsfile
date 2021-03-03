pipeline{
    agent any
 
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
                sh '''
                  cd $WORKSPACE
                  sh build.sh
                  '''
             }
        }
        /*    ----------------- Unit Test Stage ------------------- */
        stage('Unit Test'){
            steps{
                 sh '''
                    cd $WORKSPACE/test
                    mkdir build
                    cd build
                    cmake .. -DCMAKE_PREFIX_PATH=../install
                    make
                    ./app-sample-addition-test --gtest_output="xml:report.xml"

                 '''
                
              }
       }
        /*    ----------------- Coverage Test Stage ------------------- */
        stage('Coverage Test'){
            steps{
                    echo "nothing to do for coverage test yet..."

              }
       }
  

     }
     post {
        always {
            junit checksName: 'Testss', testResults: 'test/build/report.xml'
            archiveArtifacts artifacts: 'test/build/app-sample-addition-test', fingerprint: true
        
        }

    }
  }
